#include<iostream>
using namespace std;

struct Node{
		int data;
		Node* left;
		Node* right;
	Node(int key):data(key),left(nullptr),right(nullptr){}
	};

	Node* insert(Node* root,int key){
		if(root==nullptr){
			return new Node(key);
		}
		else{
			if(key<root->data){
				root->left = insert(root->left,key);
			}
			else{
					root->right=insert(root->right,key);
				}
			
	return root;
	}
}
	void inordertraversal(Node* root){
		if(root){
			inordertraversal(root->left);
			cout<<root->data<<" ";
			inordertraversal(root->right);
  		    }
		}
	void preordertraversal(Node* root){
			if(root){
			cout<<root->data<<" ";
			preordertraversal(root->left);
			preordertraversal(root->right);
			}
		}
	void postordertraversal(Node* root){
			if(root){
				postordertraversal(root->left);
				postordertraversal(root->right);
				cout<<root->data<<" ";
			}
		}
	bool search(Node* root,int key){
				if (root == nullptr){
					return false;
				}
				else if(root->data == key){
					return true;
				}
				else if(key<root->data){
						return search(root->left,key);
					}
				else{
						return search(root->right,key);
				}
			}
		Node* findmin(Node* root){
				while(root->left!= nullptr)
				{
					root= root->left;
				}
			return root;
			}
	Node* findmax(Node* root){
			while(root->right!=nullptr){
				root= root->right;
			}
		return root;
		}
	Node* remove(Node* root,int key){
			if(root==nullptr){
				return root;
			}
		else if(key<root->data){
			root->left = remove(root->left,key);
		}
		else if(key>root->data){
			root->right= remove(root->right,key);
		}
		else{
				if(root->left == nullptr){
						Node* temp = root->right;
						delete root;
						return temp;
				}
				else if(root->right== nullptr){
						Node* temp = root->left;
						delete root;
						return temp;
				}
				Node* temp = findmin(root->right);
				root->data = temp->data;
				root->right= remove(root->right,temp->data);
				}
					return root;
	}
		int main(){
			Node* root = nullptr;
			int choice,value;

			while(true){
						cout<<"Binary Search Tree Operation"<<endl;
						cout<<"1.Insert Node"<<endl;
						cout<<"2.Inorder Traversal"<<endl;
						cout<<"3.Preorder Traversal"<<endl;
						cout<<"4.PostOrder Traversal"<<endl;
						cout<<"5.Searching"<<endl;
						cout<<"6. Find Minimum Value"<<endl;
						cout<<"7. Find Maximum Value"<<endl;
						cout<<"8.Remove Node"<<endl;
						cout<<"9.Exit"<<endl;

						cout<<"Enter Your Choice"<<endl;
						cin>>choice;
						switch(choice){
									case 1:
											cout<<"Enter Value To Insert"<<endl;
											cin>>value;
											root = insert(root,value);
											break;
									case 2:
											cout<<"Inorder Traversal";
											inordertraversal(root);
											cout<<endl;
											break;
									case 3:
											cout<<"Preorder Traversal";
										    preordertraversal(root);
											cout<<endl;
											break;
									case 4:
											cout<<"Postorder Traversal";
										   postordertraversal(root);
											cout<<endl;
											break; 
									case 5:
											cout<<"Enter Value To Search";
											cin>>value;
											if(search(root,value)){
												cout<<"Value Found In The Tree"<<endl;
											}
    										else{
												cout<<"Value Not Found In The Tree"<<endl;
											}
											break;
									case 6:
								if(root!=nullptr){
									Node* minNode = findmin(root);
									cout<<"Minimum Value"<<minNode->data<<endl;
								}else{
										cout<<"Tree Is Empty"<<endl;
									}
									break;
									case 7:
									if(root!=nullptr){
									Node* maxNode = findmax(root);
									cout<<"Maximum Value"<<maxNode->data<<endl;
								}else{
										cout<<"Tree Is Empty"<<endl;
									}
									break;
								case 8:
										cout<<"Enter Value To Remove";
										cin>>value;
										root = remove(root,value);
										cout<<"Value remove from the tree"<<endl;
										break;


									case 9:
											return 0;
				
									default:
											cout<<"INvalid Choice Try Again";

							}
						}
				}
	
