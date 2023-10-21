require('dotenv').config();
const app = require("./app.js");

const PORT = process.env.PORT || 8000;
app.listen(PORT,()=>{
    console.log(`Server is up at localhost:${PORT}`);
})