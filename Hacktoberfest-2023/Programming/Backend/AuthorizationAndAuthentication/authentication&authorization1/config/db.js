const mongoose = require("mongoose");

const dbConnection = mongoose.connect(process.env.dbUrl).then((conn)=>{
    console.log(`${conn.connection.name}`);
}).catch((err)=>{
    console.log("sorry");
})
