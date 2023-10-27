#include<bits/stdc++.h>
using namespace std;
class node{
  public:
        int data;
        node*left;
        node*right;
    node(int d)
    {
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};

// Create a tree
node* createTree(node*root)
{
    int data ;
    cout<<"Enter data:"<<endl;
    cin>>data;
    //to come back if data ==-1
    if(data==-1)return NULL;
    root=new node(data); //node created 

    //we will make a call for making tree at left of inserted node and right of inserted node

    cout<<"Enter noda data to the left of  "<<data<<":"<<endl;
    root->left=createTree(root->left);//call for left tree being assigned to the left pointer of root.
    cout<<"Enter data to the right of "<<data<<":"<<endl;
    root->right=createTree(root->right);//call for the right tree being assigned to thr right of the root
    return root;
}

void bfs(node * root)
{
    if(root==NULL)return ;

    queue<node*>q;
    q.push(root);
    
    while(!q.empty())
    {
        node* temp=q.front();
        q.pop();
        cout<<temp->data<<" ";
        if(temp->left)
        {
            q.push(temp->left);
        }
        if(temp->right)
        {
            q.push(temp->right);
        }
    }
    cout<<endl;
}

int main()
{
    node*root=NULL;
    root=createTree(root);
    cout<<"The required BFS of the tree is"<<endl;
    bfs(root);

    return 0;

}