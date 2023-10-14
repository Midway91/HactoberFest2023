/*
	The question can be solved by small modification to program of Height of tree.
	The idea is quite simple. Max value of Height(leftSubtree)+Height(rightSubtree) (at any node) is the diameter. 
	Keep track of maxium diameter duing traversal and find the height of the tree.
	ans=max(ans,leftMax+rightMax); => This line maintains the max diameter.
*/
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

int diameterOfBinaryTreeHelper(TreeNode* root, int &ans) {
    if(root == NULL) return 0;
    int leftMax = diameterOfBinaryTreeHelper(root->left, ans);
    int rightMax = diameterOfBinaryTreeHelper(root->right, ans);
    ans=max(ans,leftMax+rightMax);
    return max(leftMax,rightMax)+1;
}
int diameterOfBinaryTree(TreeNode* root) {
    int ans=0;
    diameterOfBinaryTreeHelper(root,ans);
    return ans;
}
	
int main(){
	TreeNode *root=new TreeNode(0);
	root->left=new TreeNode(1);
	root->right=new TreeNode(2);
	root->left->left=new TreeNode(3);
	root->left->right=new TreeNode(4);
	root->left->left->left=new TreeNode(5);

	cout<<diameterOfBinaryTree(root);
	return 0;
}