#include <iostream>

// Define a singly linked list node structure
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to swap nodes pairwise in the linked list
Node* pairwiseSwap(Node* head) {
    // If the list is empty or has only one node, no need to swap
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    // Initialize pointers for swapping
    Node* prev = nullptr;
    Node* current = head;
    Node* newHead = nullptr;

    while (current != nullptr && current->next != nullptr) {
        Node* firstNode = current;
        Node* secondNode = current->next;
        
        // Swap the nodes
        firstNode->next = secondNode->next;
        secondNode->next = firstNode;

        // Adjust the previous pointer
        if (prev != nullptr) {
            prev->next = secondNode;
        } else {
            newHead = secondNode;
        }

        prev = firstNode;
        current = firstNode->next;
    }

    return newHead;
}

// Function to print the linked list
void printList(Node* head) {
    while (head != nullptr) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    std::cout << "Original List: ";
    printList(head);

    head = pairwiseSwap(head);

    std::cout << "List after Pairwise Swapping: ";
    printList(head);

    return 0;
}
