// index.js
require('dotenv').config();
const app = require('./app.js');
const jwt = require('jsonwebtoken');
const port = process.env.port || 5000;
app.listen(port , ()=>{
    console.log(`Server up at ${port}`);
})
