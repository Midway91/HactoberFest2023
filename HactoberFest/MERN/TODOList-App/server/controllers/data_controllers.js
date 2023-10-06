const data = require('../models/data_models');

exports.getAllData = (req, res) => {
    data.find()
        .then((data) => res.json(data))
        .catch((err) => res.status(404)
            .json({ message: 'Data not found', error: err.message }));
}

exports.postCreateData = (req, res) => {
    data.create(req.body)
        .then((data) => res.json({ message: 'Data added successfully', data }))
        .catch((err) => res.status(404)
            .json({ message: 'Failed to add data', error: err.message }));
}

exports.deleteData = (req, res) => {
    data.findByIdAndRemove(req.params.id, req.body)
        .then((data) => res.json({ message: 'Data deleted successfully', data }))
        .catch((err) => res.status(404)
            .json({ message: 'Failed to delete data', error: err.message }));
}