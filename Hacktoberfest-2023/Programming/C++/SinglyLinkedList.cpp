#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
    ~Node(){
        int value = this->data;
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }cout << "Memory is Free" << endl;
    }
};

void InsertAtHead(Node* &head , int d){
    Node* temp = new Node(d);
    temp-> next = head;
    head = temp;
}


void InsertatTail(Node* &tail,int d ){
    Node* temp = new Node(d);
    tail->next = temp;
    tail = tail->next;  

}
void DeleteAt(int position , Node* &head){
    if( position == 1){
        Node* temp = head;
        head=head->next;
        temp->next = NULL;
        delete temp;
    }
    else{
        Node* curr = head;
        Node* prev = NULL;
        int cnt = 1;
        while(cnt < position){
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;
        curr->next =NULL;
        delete curr;

    }
}


void print(Node* &head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << endl;
        temp = temp->next;
    }
    cout << endl;
}

void insertatMid(Node* &head, int postioin , int  d){
    Node* app = new Node(d);
    Node* temp = head;

    if(postioin == 1){
        InsertAtHead(head,d);
        return;
    }
    int cnt = 1;
    while(cnt < postioin-1){
        temp = temp->next;
        cnt++;

    }

    app->next = temp->next;
    temp->next = app;

}

int main(){

    Node* node1 = new Node(11);
    //cout << node1->data <<endl;
   //cout << node1->next <<endl;

   Node* head = node1;
   Node* temp = node1;
   InsertAtHead(head,9);
   InsertAtHead(head,5);
   InsertAtHead(head,3);
   //print(head); 
   insertatMid(head,1,7);
   print(head);
   DeleteAt(1,head);
   print(head);




    return 0 ;
}