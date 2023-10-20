//const { JsonWebTokenError } = require('jsonwebtoken');
const User = require('../models/UserModel');
const jwt = require('jsonwebtoken');

const createToken = (_id, role) => {
    return jwt.sign({ _id, role }, process.env.SECRET, { expiresIn: '3d' });
};

const loginUser = async (req, res) => {
    const { email, password, role } = req.body;
    try {
        const user = await User.login({email, password,role});
        const token = createToken(user._id, user.role); // Include the user's role in the token
        res.status(200).json({ email, token, role: user.role });
    } catch (err) {
        res.status(400).json({ error: err.message });
    }
};

const signupUser = async (req, res) => {
    const { email, password, role } = req.body;
    try {
        const user = await User.signup({email, password, role});
        const token = createToken(user._id, user.role); // Include the user's role in the token
        res.status(200).json({ email, token, role: user.role });
    } catch (err) {
        res.status(400).json({ error: err.message });
    }
};
const changePassword = async (req, res) => {
    const { email, role, currentPassword, newPassword, confirmNewPassword } = req.body;
    try {
      const user = await User.changePassword({ email, role, currentPassword, newPassword, confirmNewPassword });
      const token = createToken(user._id, user.role); // Include the user's role in the token
      res.status(200).json({ email, token, role: user.role });
    } catch (err) {
      res.status(400).json({ error: err.message });
    }
  };
  
  module.exports = { signupUser, loginUser, changePassword };