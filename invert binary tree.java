class Solution {
public:
    void doInvert(TreeNode* root){
        if(!root) return;
        invertTree(root->left);
        invertTree(root->right);
        swap(root->left, root->right);
    }
    
    TreeNode* invertTree(TreeNode* root) {
        doInvert(root);
        return root;
    }
};
