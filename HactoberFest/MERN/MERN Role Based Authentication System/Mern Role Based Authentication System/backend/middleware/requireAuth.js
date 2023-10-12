const jwt = require('jsonwebtoken');
const User = require('../models/UserModel'); 
const requireAuth = async (req, res, next) => {
    const {authorization} = req.headers;
    if(!authorization){
        return res.status(401).json({error:'You must be logged in'});
    }
    const token = authorization.split(' ')[1];
    try{
        const {_id, role} = jwt.verify(token, process.env.SECRET);
        const user = await User.findOne({_id}).select('_id role');
        if (!user) {
            return res.status(401).json({error: 'User not found'});
        }
        req.user = user;
        next();
    }catch(error){
        console.log(error);
        res.status(401).json({error:'You must be logged in'});
    }   
};

module.exports = requireAuth;