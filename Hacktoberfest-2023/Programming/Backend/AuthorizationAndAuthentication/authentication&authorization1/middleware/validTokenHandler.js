
// validTokenHandler.js
const jwt = require('jsonwebtoken');

exports.jwtMiddleware = async (req, res, next) => {
    try {
        // Get the access token from the request header
        const authHeader = req.headers['authorization'];   
        const token = authHeader && authHeader.split(' ')[1];
        // ho skta hai kisi jgh pe hume authHeader hi na mile qki authorization wale column m kisi ne bearer "token" na passs kiya ho therefore we use this condition 
        // const token = authHeader && authHeader.split(' ')[1];

        if (!token) {
            return res.status(401).json({ message: 'Access token missing' });
        }

        // Verify the access token
        jwt.verify(token, process.env.JWT_SECRET, async(err, decodedToken) => {
            if (err) {
                return res.status(401).json({ message: 'Invalid access token' });
            }

            req.user = decodedToken;
            next();
        });

    } catch (error) {
        console.error('Error while fetching user:', error);
        res.status(500).json({ message: 'Unable to fetch user at the moment' });
    }
};



