
// Minimum Distance Between BST Nodes
#include<bits/stdc++.h>
using namespace std;
// Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    int pre=-1, ans=INT_MAX;
    int minDiffInBST(TreeNode* root) {
        if(root->left) minDiffInBST(root->left);
        if(pre>=0) ans=min(ans, root->val-pre);
        pre=root->val;
        if(root->right) minDiffInBST(root->right);
        return ans;
    }
};
