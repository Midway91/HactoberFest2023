require('dotenv').config();
const express = require('express');
const cors = require("cors");

const connectDB = require('./config/db');

const app = express();

// routes
const data = require('./routes/data_routes');

// connect database
connectDB();

// cors
const corsOptions = {
    origin: /\.onrender\.com$/,
    methods: "GET,HEAD,PUT,PATCH,POST,DELETE",
};
app.use(cors(corsOptions));

// initialize middleware
app.use(express.json({ extended: false }));
app.get("/", (req, res) => res.send("Server is running"));

// use routes
app.use('/api/data', data);

// setting up port
const PORT = process.env.PORT || 8000;

app.listen(PORT, () => console.log(`server is running on http://localhost:${PORT}`));