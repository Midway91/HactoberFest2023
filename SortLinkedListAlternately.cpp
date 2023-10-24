#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};

void sort(Node **head);


void append(struct Node** headRef, struct Node** tailRef, int newData)
{
	struct Node* new_node = new Node(newData);
	struct Node *last = *headRef;
	if (*headRef == NULL)
	{
	    *headRef = new_node;
	    *tailRef = *headRef;
	    return;
	}
	
	(*tailRef) -> next = new_node;
	*tailRef = (*tailRef) -> next;
}

void printList(Node *head)
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

int main()
{
	int test;
	cin>>test;
	while(test--)
	{
	    struct Node* head = NULL;
	    struct Node* tail = NULL;
	    int n, k;
	    cin>>n;
	    for(int i=0; i<n ;i++){
	        cin>>k;
	        append(&head, &tail, k);
	    }
	    sort(&head);
	    printList(head);
	}
	return 0;
}

void sort(Node **head)
{
     Node* node = new Node(0);
     Node* ptr = *head;
     if(ptr->next == NULL)return;
     Node* p = node;
     while(ptr->next != NULL){
         p->next = ptr->next;
         if(ptr->next->next == NULL){
             ptr->next = NULL;
             p = p->next;
             break;
         }
         ptr->next = ptr->next->next;
         p = p->next;
         p->next =NULL;
         ptr=ptr->next;
     }
     p = node;
     node= node->next;
     while(true){
        if(node->next->next == NULL){
            node->next->next = p->next;
            p->next = node->next;
            node->next = NULL;
            break;
        }
        Node* temp = node->next->next;
        node->next->next = p->next;
        p->next = node->next;
        node->next = temp;
     }
     node = p->next;
     delete p;
     Node *fir = *head;
    Node *sec = node;
    Node *space = new Node(0);
    Node *temp = space;
    while(true){
        if(fir == NULL){
            temp->next = sec;
            break;
        }
        else if(sec == NULL){
            temp->next = fir;
            break;
        }
        else if(fir->data <= sec->data){
            temp->next = fir;
            fir = fir->next;
            temp = temp->next;
        }
        else if(fir->data > sec->data){
            temp->next = sec;
            sec= sec->next;
            temp = temp->next;
        }
    }
    ptr = space;
    space = space->next;
    *head = space;
    delete ptr;
}
