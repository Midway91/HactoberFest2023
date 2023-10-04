const Post = require('../models/postModel');
const Comment = require("../models/commentModel.js")
const Like = require('../models/likeModel.js')

// business logic
exports.commentBlog = async(req,res)=>{
    try{
        // using save function
        const {post,user,body} = req.body;
        const comment = new Comment({
            post,user,body
        });
        const savedComment = await comment.save();
        // find the post by id, add the new comment to its comment array
        const updatedPost = await Post.findByIdAndUpdate(post,{$push:{comments:savedComment._id}} , {new:true}).populate('comments').populate('likes');
        //populate the comments array with comment documents

        const likeCount = await Like.countDocuments({ post });
        const commentCount = await Comment.countDocuments({ post });

        res.json({
            post:updatedPost,
            likeCount,commentCount
        })
    }catch(err){
        console.log(err);
        return res.status(500).json({
            error:'Error while creating comment'
        })
    }
}


exports.deleteComment = async(req,res) =>{
    
    try{
        const {post,comment} = req.body ;
        const deletedComment = await Comment.findOneAndDelete({post:post,_id:comment});
        const updatedPost = await Post.findByIdAndUpdate(post,{$pull:{comments:deletedComment._id}} , {new:true}).populate("likes").populate("comments");
        
        const countLikes = await Like.countDocuments({post});
        const countcomments = await Comment.countDocuments({post});
        res.json({post:updatedPost , countLikes , countcomments});

    }catch(err){
        res.send('sorry');
        console.log(err);
    }

}
