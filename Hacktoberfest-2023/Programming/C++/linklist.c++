#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    void push(int data) {
        Node* newNode = new Node(data);
        if (top == nullptr) {
            top = newNode;
        } else {
            newNode->next = top;
            top = newNode;
        }
    }

    int pop() {
        if (isEmpty()) {
            std::cerr << "Stack is empty." << std::endl;
            return -1; // You can return a different value or throw an exception as per your requirements.
        }
        int data = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return data;
    }

    int peek() {
        if (isEmpty()) {
            std::cerr << "Stack is empty." << std::endl;
            return -1; // You can return a different value or throw an exception as per your requirements.
        }
        return top->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

int main() {
    Stack myStack;

    myStack.push(1);
    myStack.push(2);
    myStack.push(3);

    std::cout << "Top element: " << myStack.peek() << std::endl;  // Output: 3
    std::cout << "Popped element: " << myStack.pop() << std::endl; // Output: 3
    std::cout << "Is the stack empty? " << (myStack.isEmpty() ? "Yes" : "No") << std::endl; // Output: No

    return 0;
}
