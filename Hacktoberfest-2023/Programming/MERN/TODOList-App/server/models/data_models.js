const mongoose = require('mongoose');

const DataSchema = new mongoose.Schema({
    data: {
        type: "String",
        required: true,
    }
});

module.exports = mongoose.model('data', DataSchema);