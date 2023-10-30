#include <iostream>

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void preOrderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    // Visit the current node
    std::cout << root->val << " ";

    // Traverse the left subtree
    preOrderTraversal(root->left);

    // Traverse the right subtree
    preOrderTraversal(root->right);
}

int main() {
    // Create a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Perform pre-order traversal
    std::cout << "Pre-Order Traversal: ";
    preOrderTraversal(root);
    std::cout << std::endl;

    // Clean up memory (not shown in the code)

    return 0;
}
