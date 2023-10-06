const mongoose = require('mongoose');
(() => {
    mongoose.connect(process.env.DB_URL)
    .then((conn)=>{
        console.log(`Server connected to DATABASE : localhost:${conn.connection.name}`)
    }).catch((err)=>{
        console.log(err.message);
        throw new Error(`Can't connect to Database right now`);
    })
})();
