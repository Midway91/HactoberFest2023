const express = require('express');
const app = express();
const userRoutes = require('./routes/userRoutes.js');
const databaseConnection = require("./config/databaseConnection.js");

app.use(express.json());
app.use('/', userRoutes);

module.exports = app;