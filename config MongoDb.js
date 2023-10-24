const mongoose = require('mongoose');

// MongoDB connection URL (replace with your own URL)
const dbUrl = 'mongodb://localhost/mydatabase';

// Define a Mongoose schema
const userSchema = new mongoose.Schema({
  username: String,
  email: String,
});

// Create a Mongoose model based on the schema
const User = mongoose.model('User', userSchema);

// Establish the connection and define error handling
mongoose.connect(dbUrl, { useNewUrlParser: true, useUnifiedTopology: true })
  .then(() => {
    console.log('Connected to MongoDB');
  })
  .catch((error) => {
    console.error('Error connecting to MongoDB:', error);
  });

// Error handling and close on exit
mongoose.connection.on('error', (err) => {
  console.error('MongoDB connection error:', err);
});

process.on('SIGINT', () => {
  mongoose.connection.close(() => {
    console.log('MongoDB connection closed through app termination');
    process.exit(0);
  });
});
