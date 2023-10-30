#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the list
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

// Function to insert a node at the end of the list
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

// Function to insert a node at a given position
struct Node* insertAtPosition(struct Node* head, int data, int position) {
    if (position < 0) {
        printf("Invalid position.\n");
        return head;
    }
    if (position == 0) {
        return insertAtBeginning(head, data);
    }
    struct Node* newNode = createNode(data);
    struct Node* current = head;
    for (int i = 0; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Invalid position.\n");
        return head;
    }
    newNode->next = current->next;
    current->next = newNode;
    return head;
}

// Function to delete a node with a specific data value
struct Node* deleteNode(struct Node* head, int data) {
    struct Node* current = head;
    struct Node* prev = NULL;

    while (current != NULL && current->data != data) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Element not found.\n");
        return head;
    }

    if (prev == NULL) {
        head = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
    return head;
}

// Function to count the number of nodes in the list
int countNodes(struct Node* head) {
    int count = 0;
    struct Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// Function to search for a specific element in the list
int searchElement(struct Node* head, int target) {
    struct Node* current = head;
    int position = 0;

    while (current != NULL) {
        if (current->data == target) {
            return position;
        }
        current = current->next;
        position++;
    }

    return -1; // Element not found
}

// Function to reverse the linked list
struct Node* reverseList(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

// Function to display the linked list
void displayList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    head = insertAtEnd(head, 1);
    head = insertAtBeginning(head, 2);
    insertAtEnd(head, 3);
    head = insertAtPosition(head, 4, 1);
    displayList(head);

    head = deleteNode(head, 2);
    displayList(head);

    int count = countNodes(head);
    printf("Number of nodes: %d\n", count);

    int target = 3;
    int position = searchElement(head, target);
    if (position != -1) {
        printf("%d found at position %d\n", target, position);
    } else {
        printf("%d not found in the list\n", target);
    }

    head = reverseList(head);
    displayList(head);

    return 0;
}
