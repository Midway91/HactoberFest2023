#include <iostream>

using namespace std;

// Node class to represent individual elements in the doubly linked list
class Node {
public:
    int data;
    Node* next;
    Node* prev;

    // Constructor to initialize a node with data
    Node(int data) {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

// DoublyLinkedList class to manage the list
class DoublyLinkedList {
private:
    Node* head;  // Points to the first node
    Node* tail;  // Points to the last node
    int size;    // Stores the number of elements in the list

public:
    // Constructor to initialize an empty doubly linked list
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    // Append a new node with the given data to the end of the list
    void append(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            // If the list is empty, set the new node as both head and tail
            head = newNode;
            tail = newNode;
        } else {
            // Update the next and prev pointers to add the new node to the end
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    // Prepend a new node with the given data to the beginning of the list
    void prepend(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            // If the list is empty, set the new node as both head and tail
            head = newNode;
            tail = newNode;
        } else {
            // Update the next and prev pointers to add the new node to the beginning
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }

    // Remove the first node with the given data from the list
    void remove(int data) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == data) {
                // Update next and prev pointers to remove the node
                if (current->prev != nullptr)
                    current->prev->next = current->next;
                else
                    head = current->next;

                if (current->next != nullptr)
                    current->next->prev = current->prev;
                else
                    tail = current->prev;

                delete current;
                size--;
                return;
            }
            current = current->next;
        }
    }

    // Display the elements of the list
    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " <-> ";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }

    // Get the size (number of elements) of the list
    int getSize() {
        return size;
    }
};

int main() {
    // Example usage of the DoublyLinkedList class
    DoublyLinkedList dll;
    dll.append(1);
    dll.append(2);
    dll.append(3);
    dll.prepend(0);

    cout << "Doubly Linked List: ";
    dll.display();

    dll.remove(2);

    cout << "After removing 2: ";
    dll.display();

    cout << "Size of the list: " << dll.getSize() << endl;

    return 0;
}
