const Post = require('../models/postModel.js');
const Like = require('../models/likeModel.js');
const Comment = require('../models/commentModel.js');

exports.likeBlog = async(req,res)=>{
    try{
        const {user,post} = req.body;
        const like = new Like({
            user,post
        }) ;
        const savedLike = await like.save();

        // update the like wala array of the post collection
        const updatedPost = await Post.findByIdAndUpdate(post,{$push:{likes:savedLike._id}} ,{new:true})
        .populate('likes').populate("comments");

        const likeCount = await Like.countDocuments({ post });
        const commentCount = await Comment.countDocuments({ post });
        
        res.json({post:updatedPost , likeCount, commentCount});
    }catch(err){
        res.status(500).json({
            success:false,
            message:"can't like this blog"
        })
    }
}


exports.unlikeBlog = async(req,res)=>{
    try{
        const{post,like} = req.body;
        // find and delete from the like collection
        const deletedLike = await Like.findOneAndDelete({post:post, _id:like});

        // update the post collection
        const updatedPost = await Post.findByIdAndUpdate(post,{$pull:{likes:deletedLike._id}} , {new:true}).populate("likes").populate("comments");

        const countLikes = await Like.countDocuments({post});
        const countcomments = await Comment.countDocuments({post});
        res.json({post:updatedPost , countLikes , countcomments});
    }catch(err){
        res.send('sorry');
        console.log(err);
    }
}