const express = require("express");
const mongoose = require("mongoose");
const bodyParser = require("body-parser");
const cors = require("cors");
require("dotenv").config();
const app = express();
const PORT=process.env.PORT || 8070;
const corsOptions = {
    origin: 'http://localhost:3000',
    credentials: true, //access-control-allow-credentials:true
  };
  
app.use(cors(corsOptions));
app.use(bodyParser.json());

const URL=process.env.MONGODB_URL;
mongoose.connect(URL,{
    //useCreateIndex:true,
    useNewUrlParser:true,
    useUnifiedTopology:true,
    //useFindAndModify:false
});
const connection=mongoose.connection;
connection.once("open",()=>{
    console.log("MongoDB Connection Success!");
})


const patientRouter=require("./routes/patients.js");
app.use("/patient",patientRouter);
const doctorRouter=require("./routes/doctors.js");
app.use("/doctor",doctorRouter);
const nurseRouter=require("./routes/nurses.js");
app.use("/nurse",nurseRouter);
const staffRouter=require("./routes/staffs.js");
app.use("/staff",staffRouter);
const equipmentRouter=require("./routes/equipments.js");
app.use("/equipment",equipmentRouter);
const mealRouter=require("./routes/meals.js");
app.use("/meal",mealRouter);
const notificationRouter=require("./routes/notifications.js");
app.use("/notification",notificationRouter);
const packagesRouter=require("./routes/packages.js");
app.use("/package",packagesRouter);
const paymentRouter=require("./routes/payments.js");
app.use("/payment",paymentRouter);
const serviceRouter=require("./routes/services.js");
app.use("/service",serviceRouter);

const userRoutes=require("./routes/user.js");
app.use("/user",userRoutes);


app.listen(PORT,()=>{
    console.log(`Server is up and running on port: ${PORT}`);
})