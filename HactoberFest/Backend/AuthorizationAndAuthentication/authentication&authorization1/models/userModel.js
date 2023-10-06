// userModel.js
const mongoose = require("mongoose")
const jwt = require('jsonwebtoken');
const user = new mongoose.Schema({
    name: {
        type: String,
        required: true
    },
    email: {
        type: String,
        required: true
    },
    password: {
        type: String,
        required: true,
        select: true
    },
    resetPasswordToken: String,
    resetPasswordExpires: Date, 
}, { timestamps: true });


module.exports = mongoose.model("manveer", user);


