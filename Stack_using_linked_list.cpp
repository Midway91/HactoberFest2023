// C++ program to Implement a stack
// using singly linked list
#include <bits/stdc++.h>
#include<iostream>
using namespace std;
 
// creating a linked list;

class Node {

public:

    int data;

    Node* next;

   

    // Constructor for initialising

    Node(int n)

    {

        this->data = n;

        this->next = NULL;

    }
};
 

class Stack {

    Node* top;
 

public:
//constructor for initialisating top pointer of stack
    Stack() { top = NULL; }
 

    void push(int d)

    {
 

        // Create new node temp and allocate memory in heap 

  Node* temp = new Node(d);
 

        // Check if stack (heap) is full.

        // Then inserting an element would

        // lead to stack overflow

        if (!temp) {

            cout << "\nStack Overflow";

            exit(1);

        }
 

        // Initialize data into temp data field

        temp->data = d;
 

        // Updating the temp pointer to point to top

        temp->next = top;
 

        // Make temp as top of Stack

        top = temp;
      cout<<endl<<d<<" is pushed \n";

    }
 

    // Utility function to check if

    // the stack is empty or not

    bool isEmpty()

    {

        // If top is NULL it means that

        // there are no elements are in stack

        return top == NULL;

    }
 

    // Utility function to return top element in a stack

    int peek()

    {

        // If stack is not empty , return the top element

        if (!isEmpty())

            return top->data;

        else

            exit(1);

    }
 

    // Function to remove
void pop()

    {

        Node* temp;
 

        // Check for stack underflow

        if (top == NULL) {

            cout << "\nStack Underflow" << endl;

            exit(1);

        }

        else {
  
        
            // Assign top to temp

            temp = top;
         int val=temp->data;
          cout<<"\nValue popped is : " <<val<<endl;

            // Assign second node to top

            top = top->next;
 

            // This will automatically destroy

            // the link between first node and second node
 

            // Release memory of top node

            // i.e delete the node

            free(temp);

        }

    }
 

    // Function to print all the

    // elements of the stack

    void display()

    {

        Node* temp;
 

        // Check for stack underflow

        if (top == NULL) {

            cout << "\nStack Underflow";

            exit(1);

        }

        else {
cout<<"\nDisplaying elements of stack \n";
            temp = top;

            while (temp != NULL) {
 

                // Print node data

                cout << temp->data;
 

                // Assign temp link to temp

        temp = temp->next;
              if (temp != NULL)

                    cout << " -> ";

            }

        }

    }
};
 
// Driven Program

int main()
{

    // Creating a stack

    Stack s;
 

    // Push the elements of stack

    s.push(23);

    s.push(35);

    s.push(3);

    s.push(48);
 

    // Display stack elements

    s.display();
 

    // Print top element of stack

    cout << "\nTop element is " << s.peek() << endl;
 

    // Delete top elements of stack

    s.pop();

    s.pop();
 

    // Display stack elements

    s.display();
 

    // Print top element of stack

    cout << "\nTop element is " << s.peek() << endl;
 

    return 0;
}