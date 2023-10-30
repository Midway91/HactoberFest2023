// userController.js
const userModel = require('../models/userModel.js');
const bcrypt = require('bcrypt');
const jwt = require('jsonwebtoken');
const utils = require('../randomToken.js');
const emailValidator = require("email-validator");


exports.home = async (req, res) => {
    res.send("You are currently at home");
};

exports.signup = async (req, res) => {
    try {
        const { name, email, password } = req.body;
        const existingMailId = await userModel.findOne({ email });
        if (existingMailId) {
            return res.status(400).json({
                success: false,
                message: "The user already registered. Go and sign in"
            })
        }
        if (!name || !email || !password) {
            return res.status(400).json({
                success: false,
                message: "All the fields are required !"
            })
        }



        const validEmail = emailValidator.validate(email);
        if (!validEmail) {
            return res.status(400).json({
                success: false,
                message: "Please provide a valid email address 📩"
            });
        }

        // hash password
        const hashedPassword = await bcrypt.hash(password, 10); //The higher the number, the more secure the hash will be, but it will also take longer to compute. Therefore, it's a balance between security and performance.
        // console.log("hashed password is :", hashedPassword);
        const newUser = await userModel.create({ name, email, password: hashedPassword });
        res.status(200).json({
            success: true,
            message: "User has been successfully registered",
            newUser
        });
    } catch (error) {
        res.status(500).json({ success: false, message: "Unable to register new users rn" });
        console.log(error);
    }

}

exports.signin = async (req, res) => {
    try {
        const { email, password } = req.body;
        if (!email || !password) {
            res.status(400).json({ message: 'All fields are required' });
        }
        const existingUser = await userModel.findOne({ email });
        if (existingUser && (await bcrypt.compare(password, existingUser.password))) {
            const accessToken = jwt.sign({
                name: existingUser.name,
                email: existingUser.email,
                id: existingUser._id,
            }, process.env.JWT_SECRET, { expiresIn: "1m" });
            res.status(200).json({
                accessToken,
                message:"User successfully signed in"
            })
        } else {
            res.status(401).send("email or password is incorrect");
        }
    } catch (error) {
        console.log(error);
        res.status(500).json({ message: "Unable to sign you in rn" });
    }
}

exports.getuser = async (req, res) => {
    try {
        const user = await userModel.findById(req.user.id);

        if (!user) {
            return res.status(404).json({ message: 'User not found' });
        }

        res.status(200).json({
            id: user._id,
            name: user.name,
            email: user.email
        });
    } catch (error) {
        console.error('Error while fetching user:', error);
        res.status(500).json({ message: 'Unable to fetch user at the moment' });
    }
};

exports.logout = (req, res) => {
    try {
        res.status(200).json({
            accessToken: null, // Sending a null token means the token is invalid/expired
            message: `user has been successfully logged out`
        });
    } catch (error) {
        console.log(error);
        res.status(500).json({ message: "Unable to logout at the moment" });
    }
};

exports.forgotPassword = async (req, res) => {
    try {
        const { email } = req.body;
        const user = await userModel.findOne({ email });

        if (!user) {
            return res.status(404).json({ message: 'User not found' });
        }

        // Generate reset token
        const resetToken = utils.generateRandomToken(32);
        user.resetPasswordToken = resetToken;
        user.resetPasswordExpires = Date.now() + 10 * 60 * 1000;

        // Save the reset token and expiration time to the user document
        await user.save();

    } catch (error) {
        console.error('Error while processing forgot password:', error);
        res.status(500).json({ message: 'Unable to process forgot password request' });
    }
};

exports.resetPassword = async (req, res) => {
    try {
        const { token } = req.params;
        const { password } = req.body;

        // console.log('Received reset token:', token);

        // Find the user by the reset token and check if it's still valid
        const user = await userModel.findOne({
            resetPasswordToken: token,
            resetPasswordExpires: { $gt: Date.now() }, // Check if the token is not expired
        });

        // console.log('User found:', user);

        if (!user) {
            console.log('Token is invalid or expired.');
            return res.status(400).json({ message: 'Invalid or expired token' });
        }

        // Update the user's password
        user.password = await bcrypt.hash(password, 10);
        user.resetPasswordToken = undefined;
        user.resetPasswordExpires = undefined;
        await user.save();

        console.log('Password reset successful for user:', user.name);

        res.status(200).json({ message: 'Password reset successful' });
    } catch (error) {
        console.error('Error while resetting password:', error);
        res.status(500).json({ message: 'Unable to reset password' });
    }
};
