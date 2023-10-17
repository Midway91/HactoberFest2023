
#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};
int height(node* root,int &dia){
    if(root==NULL) return 0;
    int lh=height(root->left,dia);
    int rh=height(root->right,dia);
    dia=max(dia,lh+rh);
    return 1+max(lh,rh); 

}
int diaOfBT(node* root){
    int dia=0;
    height(root,dia);
    return dia;
}
int main(){
    node* root=new node(3);
    root->left=new node(7);
    root->right=new node(20);
    root->right->left=new node(15);
    root->right->right=new node(7);
 cout<< diaOfBT(root);
}
// TC-O(N)
// SC-O(N)