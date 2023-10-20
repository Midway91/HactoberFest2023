#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

// Implementation of Binary Tree
template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode()
    {
        delete left;
        delete right;
    }
};

/*********************************  PRINT AND TAKE INPUT  ***********************************/

// Take input recursively
BinaryTreeNode<int> *takeInputRecursive()
{
    int data;

    cin >> data;
    BinaryTreeNode<int> *root;
    if (data != -1)
        root = new BinaryTreeNode<int>(data);
    else
        return NULL;
    cout << "Enter left child of " << data << endl;
    root->left = takeInputRecursive();
    cout << "Enter right child of " << data << endl;
    root->right = takeInputRecursive();

    return root;
}

// Print the tree recursively
void printTreeRecursive(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;
    cout << root->data << " : ";
    if (root->left != NULL)
    {
        cout << "L" << root->left->data;
    }

    if (root->right != NULL)
    {
        cout << " R" << root->right->data;
    }
    cout << endl;
    printTreeRecursive(root->left);
    printTreeRecursive(root->right);
}

// Take input level wise
BinaryTreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cout << "Enter root data" << endl;
    cin >> rootData;

    if (rootData == -1)
        return NULL;

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> nodes;
    nodes.push(root);

    while (!nodes.empty())
    {
        BinaryTreeNode<int> *parent = nodes.front();
        nodes.pop();

        int leftData, rightData;
        cout << "Enter left child data of " << parent->data << endl;
        cin >> leftData;
        if (leftData != -1)
        {
            BinaryTreeNode<int> *leftChild = new BinaryTreeNode<int>(leftData);
            parent->left = leftChild;
            nodes.push(leftChild);
        }

        cout << "Enter right child data of " << parent->data << endl;
        cin >> rightData;
        if (rightData != -1)
        {
            BinaryTreeNode<int> *rightChild = new BinaryTreeNode<int>(rightData);
            parent->right = rightChild;
            nodes.push(rightChild);
        }
    }

    return root;
}

// print the tree level wise
void printLevelWise(BinaryTreeNode<int> *root)
{
    queue<BinaryTreeNode<int> *> nodes;
    nodes.push(root);

    while (!nodes.empty())
    {
        BinaryTreeNode<int> *parent = nodes.front();
        nodes.pop();

        cout << parent->data << ":";
        if (parent->left != NULL)
        {
            BinaryTreeNode<int> *leftChild = parent->left;
            cout << "L:" << leftChild->data << ",";
            nodes.push(leftChild);
        }
        else
        {
            cout << "L:-1"
                 << ",";
        }

        if (parent->right != NULL)
        {
            BinaryTreeNode<int> *rightChild = parent->right;
            cout << "R:" << rightChild->data;
            nodes.push(rightChild);
        }
        else
        {
            cout << "R:-1";
        }

        cout << endl;
    }
}

/*********************************  PROPERTIES OF TREES  ***********************************/

// Counts the number of nodes
int countNodes(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return 0;

    return countNodes(root->left) + countNodes(root->right) + 1;
}

// checks if a data value is preset in the tree or not
bool isNodePresent(BinaryTreeNode<int> *root, int x)
{
    if (root == NULL)
        return false;

    if (root->data == x)
        return true;

    return isNodePresent(root->left, x) || isNodePresent(root->right, x);
}

// Height of the binary tree
int height(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return 0;

    return 1 + max(height(root->left), height(root->right));
}

// Diameter of Binary Tree using pure recursion
int diameter(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return 0;

    int option1 = height(root->left) + height(root->right);
    int option2 = diameter(root->left);
    int option3 = diameter(root->right);

    return max(option1, max(option2, option3));
}

// Diamter of Binary Tree using pairs
pair<int, int> diameterBetter(BinaryTreeNode<int> *root)
{
    pair<int, int> hd;
    if (root == NULL)
    {
        hd = make_pair(0, 0);
        return hd;
    }

    pair<int, int> leftAns = diameterBetter(root->left);
    pair<int, int> rightAns = diameterBetter(root->right);
    int lh = leftAns.first, ld = leftAns.second;
    int rh = rightAns.first, rd = rightAns.second;

    int height = 1 + max(lh, rh);
    int diameter = max(lh + rh, max(ld, rd));

    hd = make_pair(height, diameter);
    return hd;
}

// Function to make a mirror of the Binary Tree
void mirrorBinaryTree(BinaryTreeNode<int> *root)
{
    // Write your code here
    if (root == NULL)
        return;

    mirrorBinaryTree(root->left);
    mirrorBinaryTree(root->right);

    BinaryTreeNode<int> *temp = root->left;
    root->left = root->right;
    root->right = temp;
}

// function to find max and min both of a tree
pair<int, int> getMinAndMax(BinaryTreeNode<int> *root)
{

    pair<int, int> minmax;
    // Base case
    if (root == NULL)
    {
        minmax = make_pair(INT_MAX, 0);
        return minmax;
    }

    pair<int, int> leftMinmax = getMinAndMax(root->left);
    pair<int, int> rightMinmax = getMinAndMax(root->right);

    int minimum = min(root->data, min(leftMinmax.first, rightMinmax.first));
    int maximum = max(root->data, max(leftMinmax.second, rightMinmax.second));

    minmax = make_pair(minimum, maximum);
    return minmax;
}

vector<int> *getRootToNodePath(BinaryTreeNode<int> *root, int data)
{
    if (root == NULL)
        return NULL;

    if (root->data == data)
    {
        vector<int> *output = new vector<int>();
        output->push_back(root->data);
        return output;
    }

    vector<int> *leftOutput = getRootToNodePath(root->left, data);
    if (leftOutput != NULL)
    {
        leftOutput->push_back(root->data);
        return leftOutput;
    }

    vector<int> *rightOutput = getRootToNodePath(root->right, data);
    if (rightOutput != NULL)
    {
        rightOutput->push_back(root->data);
        return rightOutput;
    }

    return NULL;
}

/*********************************  TRAVERSALS  ***********************************/

// inorder
void inorder(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// preorder
void preorder(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    inorder(root->left);
    inorder(root->right);
}

// postorder
void postorder(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    inorder(root->right);
    cout << root->data << " ";
}

/*********************************  MENU OF TREE  ***********************************/

int main()
{
    cout << "\nEnter 1 if you want to take input and print recursively" << endl;
    cout << "\nEnter 2 if you want to take input and print level wise" << endl;
    int choice;
    cin >> choice;

    BinaryTreeNode<int> *root;
    if (choice == 1)
    {
        root = takeInputRecursive();
        cout << "\nYour Tree is : " << endl
             << endl;
        printTreeRecursive(root);
    }
    else
    {
        root = takeInputLevelWise();
        cout << "\nYour Tree is : " << endl
             << endl;
        printLevelWise(root);
    }

    char ch;
    cout << "\nWant to perform any operations on the tree? (y/n) : ";
    cin >> ch;
    while (ch == 'y' || ch == 'Y')
    {
        cout << "\nPERFORM OPERATIONS ON TREE :";
        cout << "\n1. Number of Nodes :";
        cout << "\n2. Find a node";
        cout << "\n3. Height";
        cout << "\n4. Diameter";
        cout << "\n5. Make a mirror of the tree";
        cout << "\n6. Max and Min in the tree";
        cout << "\n7. Root to node Path";
        cout << "\n8. Traversals";

        int option;
        cout << "\n\nEnter the operation you want to peform : ";
        cin >> option;

        switch (option)
        {
        case 1:
        {
            cout << "\nThe number of nodes present in the Tree is " << countNodes(root) << endl;
            break;
        }
        case 2:
        {
            cout << "\nEnter the node data you want to search : ";
            int value;
            cin >> value;
            if (isNodePresent(root, value))
                cout << "\nNode is present\n";
            else
                cout << "\nNode is not present\n";
            break;
        }
        case 3:
        {
            cout << "\nThe height of the tree is " << height(root) << endl;
            break;
        }
        case 4:
        {
            cout << "\nThe diameter of the tree is " << diameterBetter(root).second << endl;
            break;
        }
        case 5:
        {
            BinaryTreeNode<int> *mirror = root;
            mirrorBinaryTree(mirror);
            cout << "\nMirrored Binary Tree" << endl;
            printLevelWise(mirror);
            cout << endl;
            break;
        }
        case 6:
        {
            cout << "\nThe min is " << getMinAndMax(root).first << "\nThe max is " << getMinAndMax(root).second << endl;
            break;
        }
        case 7:
        {
            cout << "\nEnter the node whose path you want to find : ";
            int node;
            cin >> node;
            vector<int> *path = getRootToNodePath(root, node);
            if (path == NULL)
                cout << "\nNode not found, path does not exist\n";
            else
            {
                for (int i = 0; i < path->size(); i++)
                {
                    cout << path->at(i) << " ";
                }
                cout << endl;
            }
            break;
        }
        case 8:
        {
            cout << "\n\nTRAVERSAL MENU";
            cout << "\n1. Pre order Traversal";
            cout << "\n2. Post order Traversal";
            cout << "\n3. In order Traversal";
            cout << "\nEnter you choice : ";
            int traversal_choice;
            cin >> traversal_choice;
            switch (traversal_choice)
            {
            case 1:
            {
                cout << "\nPreorder Traversal\n";
                preorder(root);
                cout << endl;
                break;
            }
            case 2:
            {
                cout << "\nPostorder Traversal\n";
                postorder(root);
                cout << endl;
                break;
            }
            case 3:
            {
                cout << "\nInorder Traversal\n";
                inorder(root);
                cout << endl;
                break;
            }
            default:
                cout << "Invalid option!!";
                break;
            }
            break;
        }
        default:
            cout << "\nOption not known!";
            break;
        }

        cout << "\nWant to perform any more operations on the tree? (y/n) : ";
        cin >> ch;
    }

    cout << "\nGood Bye :(\n"
         << endl;
}

// Example inputs:
// 1 2 3 4 5 6 7 -1 -1 8 9 -1 -1 -1 -1 -1 -1 -1 -1
// 1 2 3 4 5 -1 -1 6 7 -1 10 -1 -1 8 -1 11 12 -1 9 -1 -1 13 -1 -1 -1 -1 -1