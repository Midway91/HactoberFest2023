const express = require('express');
const router = express.Router();

const {home} = require("../controllers/home.js");
const {createBlog,getAllBlogs} = require("../controllers/createBlog.js")
const {commentBlog,deleteComment} = require('../controllers/createComment.js');
const {likeBlog,unlikeBlog} = require('../controllers/likeBlog.js');

router.get('/', home);
router.post('/writeblog',createBlog);
router.get('/getallblogs',getAllBlogs);
router.post('/writecomment',commentBlog);
router.post('/createlike',likeBlog);
router.post('/createunlike',unlikeBlog);
router.post('/deletecomment',deleteComment);


module.exports = router;