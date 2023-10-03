#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node* next = NULL;

    // constructor
    Node(int data)
    {
        this-> data = data;
        this-> next = NULL;
    }
};
void insertAtHead(Node* &head,int data)
{
    Node* temp = new Node(data);
    temp-> next = head;
    head = temp;
}

void print(Node* &head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int main()
{
    Node* head = new Node(10);
    insertAtHead(head,20);
    print(head);
    return 0;

}
