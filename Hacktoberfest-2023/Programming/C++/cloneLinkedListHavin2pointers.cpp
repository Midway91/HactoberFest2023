#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int value) {
        val = value;
        next = NULL;
        random = NULL;
    }
};

Node* copyRandomList(Node* head) {
    // Step 1: Duplicate nodes and insert them between original nodes
    Node* temp = head;
    while (temp != NULL) {
        Node* newNode = new Node(temp->val);
        newNode->next = temp->next;
        temp->next = newNode;
        temp = temp->next->next;
    }

    // Step 2: Copy random pointers
    Node* itr = head;
    while (itr != NULL) {
        if (itr->random != NULL)
            itr->next->random = itr->random->next;
        itr = itr->next->next;
    }

    // Step 3: Split the original and copied lists
    Node* dummy = new Node(0);
    itr = head;
    temp = dummy;
    Node* fast;
    while (itr != NULL) {
        fast = itr->next->next;
        temp->next = itr->next;
        itr->next = fast;
        temp = temp->next;
        itr = fast;
    }

    return dummy->next;
}

void printList(Node* head) {
    while (head != NULL) {
        cout << head->val << ':';
        head->next != NULL ? cout << head->next->val : cout << "NULL";
        head->random != NULL ? cout << "," << head->random->val : cout << ",NULL";
        cout << endl;
        head = head->next;
    }
}

int main() {
    Node* head = NULL;

    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);

    head = node1;
    head->next = node2;
    head->next->next = node3;
    head->next->next->next = node4;

    head->random = node4;
    head->next->random = node1;
    head->next->next->random = NULL;
    head->next->next->next->random = node2;

    cout << "Original list: (current node: node pointed by next pointer, node pointed by random pointer)\n";
    printList(head);

    cout << "Copy list: (current node: node pointed by next pointer, node pointed by random pointer)\n";
    Node* newHead = copyRandomList(head);
    printList(newHead);

    return 0;
}
