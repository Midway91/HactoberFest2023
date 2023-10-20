// userRouter.js 
const express = require('express');
const router = express.Router();
const jwtMiddleware = require('../middleware/validTokenHandler.js');
const {home,signup,signin, getuser,logout,forgotPassword,resetPassword} = require('../controllers/userController.js');




router.get('/', home);
router.post('/signup', signup);
router.post('/signin', signin);
router.get('/getuser', jwtMiddleware.jwtMiddleware, getuser);
router.get('/logout', logout);
router.post('/forgotpassword', forgotPassword);
router.post('/resetpassword/:token', resetPassword);
module.exports = router;


