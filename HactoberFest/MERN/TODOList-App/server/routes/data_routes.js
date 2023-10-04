const express = require('express');

const router = express.Router();

const { getAllData, postCreateData, deleteData } = require('../controllers/data_controllers');

router.get("/", getAllData);

router.post("/", postCreateData);

router.delete("/:id", deleteData);

module.exports = router;