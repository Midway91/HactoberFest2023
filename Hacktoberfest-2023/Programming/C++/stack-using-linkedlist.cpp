#include <iostream>

// Define the Node structure for the linked list
struct Node {
    int data;
    Node* next;

    explicit Node(int data) : data(data), next(nullptr) {}  // Constructor for a node
};

class Stack {
    Node* top;  // Pointer to the top of the stack

public:
    // Constructor to initialize an empty stack
    explicit Stack() : top(nullptr) {}

    // Check if the stack is empty
    bool empty() const {
        return this->top == nullptr;
    }

    // Push operation: insert an element into the stack
    void push(int x) {
        if (empty()) {
            top = new Node(x);
            return;
        }
        Node* t = new Node(x);
        t->next = top;
        top = t;
    }

    // Pop operation: remove an element from the stack
    int pop() {
        if (this->empty()) {
            std::cerr << "Stack underflow!\n"; // Print an error message if the stack is empty
            return -1;
        }

        int x = top->data;
        Node* t = top;
        top = top->next ? top->next : nullptr;
        delete t;
        return x;
    }

    // Overloaded << operator for printing the stack
    friend std::ostream& operator<<(std::ostream& os, const Stack& stack) {
        Node* t = stack.top;
        while (t) {
            os << t->data << std::endl;
            t = t->next;
        }
        os << std::endl;
        return os;
    }

    // Get the top element of the stack without removing it
    int peek() {
        return empty() ? -1 : this->top->data;
    }

    // Destructor to free up heap memory used by the linked list
    virtual ~Stack() {
        Node* t = this->top;
        while (t) {
            top = top->next;
            delete t;
            t = top;
        }
    }
};

int main() {
    Stack stk;  // Create a stack object
    stk.push(4);  // Push elements onto the stack
    stk.push(10);
    stk.push(422);
    stk.pop();  // Pop an element from the stack
    std::cout << stk.peek();  // Print the top element of the stack
    return 0;
}
