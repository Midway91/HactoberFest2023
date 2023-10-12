#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
		int pr;
		Node(int value,int priority){
			data=value;
			next=NULL;
			pr=priority;
		}		
};
	
	
class pr_queue{
	Node *front;
public:
	pr_queue(){
		front=NULL;
	}
	void insert(int value,int priority);
	void remove();
	bool isempty();
	void display();	
};	

void pr_queue :: insert(int value,int priority){
	Node* newnode=new Node(value,priority);
	if(front==NULL || priority>front->pr){
		newnode->next=front;
		front=newnode;
		return;		
	}
	Node *curr=front;
	while(curr->next && curr->next->pr>priority){
		curr=curr->next;
	}
	newnode->next=curr->next;
	curr->next=newnode;	
}

void pr_queue :: remove(){
	if(!front){
		cout<<"List is empty, Nothing to remove"<<endl;
		return;
	}
	Node* temp=front;
	front=front->next;
	delete temp;	
}

void pr_queue :: display(){
	if(front==NULL){
		cout<<"List is empty, Nothing to display."<<endl;
	}
	else{
		Node *temp=front;
		while(temp){
			cout<<"Data: "<<temp->data<<" Priority: "<<temp->pr<<endl;
			temp=temp->next;
		}
	}
}

bool pr_queue :: isempty(){ 
	return(!front);
}	


int main(void){
	pr_queue p;
	int value,choice,priority;
	cout<<"Select choice"<<endl<<"1.Insert "<<endl<<"2.Remove the first one"<<endl<<"3.empty"<<endl<<"4.display"<<endl<<"5.exit"<<endl;
	cin>>choice;
	while(choice<=4){
		switch(choice){
			case 1:				
				cout<<"Enter the number :";
				cin>>value;
				cout<<"Enter priority order :";
				cin>>priority;
				p.insert(value,priority);
				break;
			case 2:				
				p.remove();
				break;
			case 3:
				if(p.isempty()){
					cout<<"List is empty \n"<<endl;					
				}
				else cout<<"List is not empty \n"<<endl;
				break;	
			case 4:
				cout<<"Elements are: "<<endl;
				p.display();				
				break;			
			default:
				cout<<"Invalid input. give correct input."<<endl;
					
		}	
	cout<<"Enter the choice :";			
	cin>>choice;
	}
	return 0;
}
















	
