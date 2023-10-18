#include <iostream>
#include <climits>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isValidBST(TreeNode* root, long long min_val = LLONG_MIN, long long max_val = LLONG_MAX) {
    if (root == nullptr) {
        return true;
    }

    // Check if the current node's value is within the valid range
    if (root->val <= min_val || root->val >= max_val) {
        return false;
    }

    // Recursively check the left subtree with updated maximum value
    // and the right subtree with updated minimum value
    return isValidBST(root->left, min_val, root->val) && isValidBST(root->right, root->val, max_val);
}

int main() {
    // Example usage
    //       2
    //      / \
    //     1   3
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    if (isValidBST(root)) {
        std::cout << "Valid BST" << std::endl;
    } else {
        std::cout << "Not a valid BST" << std::endl;
    }

    // Clean up the allocated memory
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
