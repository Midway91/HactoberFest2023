#include <iostream>

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void inOrderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    // Traverse the left subtree
    inOrderTraversal(root->left);

    // Visit the current node
    std::cout << root->val << " ";

    // Traverse the right subtree
    inOrderTraversal(root->right);
}

int main() {
    // Create a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Perform in-order traversal
    std::cout << "In-Order Traversal: ";
    inOrderTraversal(root);
    std::cout << std::endl;

    // Clean up memory (not shown in the code)

    return 0;
}
