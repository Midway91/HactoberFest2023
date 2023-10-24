
#include <iostream>
#include <queue>

struct TreeNode
{
  int data;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

void levelOrderTraversal(TreeNode *root)
{
  if (root == nullptr)
  {
    return;
  }

  std::queue<TreeNode *> q;
  q.push(root);

  while (!q.empty())
  {
    TreeNode *current = q.front();
    q.pop();

    std::cout << current->data << " ";

    if (current->left != nullptr)
    {
      q.push(current->left);
    }

    if (current->right != nullptr)
    {
      q.push(current->right);
    }
  }
}

int main()
{
  // Create binary tree
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);

  std::cout << "Level Order Traversal: ";
  levelOrderTraversal(root);

  return 0;
}
