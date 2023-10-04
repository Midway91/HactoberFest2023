const Post = require('../models/postModel.js');
exports.createBlog = async(req,res) =>{
    try{
        const {title,body} = req.body ;
        const post = new Post({
            title,body
        });
        const savedPost = await post.save();

        res.json({
            post:savedPost
        })

    }catch(err){
        return res.status(400).json({
            message:"sorry can't post blog right now"
        })
    }
}


exports.getAllBlogs = async(req,res)=>{
    try{
        const posts = await Post.find({}).populate("comments").populate('likes');
        res.json({posts});
    }
    catch(err){
        res.status(500).json({
            success:false,
            message:"Cn't fetch blogs right now"
        });
    }
}