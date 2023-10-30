#include<iostream>

using namespace std;

typedef struct node{
    int number;
    struct node *left;
    struct node *right;
}node;

node* createnode(int val){
    node* NewNode = (node*)malloc(sizeof(node));
    NewNode->number=val;
    NewNode->left=NULL;
    NewNode->right=NULL;
    return NewNode;
}

node* leftnode(node* root,int val){
    root->left=createnode(val);
    return root->left;
}

node* rightnode(node* root,int val){
    root->right=createnode(val);
    return root->right;
}

int height(node* root){
    if(root==NULL){
        return 0;
    }
    else{
        int left_height=height(root->left);
        int right_height=height(root->right);
        
        if(left_height>right_height){
            return (left_height+1);
        }
        else{
            return right_height+1;
        }
    }
}
void printCurrentLevel(node* root,int x){
    if(root==NULL){
        return ;
    }
    if(x==1){
        cout << root->number << "->";
    }
    else{
        printCurrentLevel(root->left, x-1);
        printCurrentLevel(root->right, x-1);
        
    }
}
void levelorder(node* root){
    int h = height(root);
    for (int i = 1; i <= h; i++){
        printCurrentLevel(root, i);
    }
    
}
 




int  main(){
    node* root = NULL;
    root = createnode(15);
    leftnode(root,10);
    rightnode(root,20);
    leftnode(root->left,5);
    rightnode(root->left,13);

    levelorder(root);
}