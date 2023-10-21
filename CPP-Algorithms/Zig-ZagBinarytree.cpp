/* A zigzag traversal, also known as a "snake" traversal, is a way to traverse a binary tree or any other hierarchical data structure in a zigzag pattern */
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (!root) {
        return result;
    }

    queue<TreeNode*> q;
    q.push(root);
    bool leftToRight = true;

    while (!q.empty()) {
        int levelSize = q.size();
        vector<int> levelValues(levelSize);

        for (int i = 0; i < levelSize; ++i) {
            TreeNode* current = q.front();
            q.pop();

            int index = leftToRight ? i : (levelSize - 1 - i);
            levelValues[index] = current->val;

            if (current->left) {
                q.push(current->left);
            }
            if (current->right) {
                q.push(current->right);
            }
        }

        result.push_back(levelValues);
        leftToRight = !leftToRight;
    }

    return result;
}


TreeNode* createBinaryTree() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    return root;
}

int main() {
    TreeNode* root = createBinaryTree();
    vector<vector<int>> result = zigzagLevelOrder(root);

    cout << "Zigzag Traversal of Binary Tree:" << endl;
    for (const vector<int>& level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
