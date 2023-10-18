// app.js
const express = require("express");
const app = express() ;
app.use(express.json());

const dbConnection = require('./config/db.js');


const userRoutes = require('./routes/userRoutes.js');
app.use('/', userRoutes);

module.exports = app ;


