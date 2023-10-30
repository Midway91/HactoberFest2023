#include <iostream>

// Linked list Node
struct ListNode {
    int data;
    ListNode* next;

    ListNode(int d) : data(d), next(nullptr) {}
};

bool isLoopPresent(ListNode* nodeHead) {
    ListNode* slowPointer = nodeHead;
    ListNode* fastPointer = nodeHead;

    // We will use a flag to know if a loop was found
    bool loopFound = false;

    while (fastPointer != nullptr) {
        fastPointer = fastPointer->next;

        if (fastPointer != nullptr) {
            fastPointer = fastPointer->next;
            slowPointer = slowPointer->next;
        }

        if (fastPointer == slowPointer) {
            loopFound = true;
            // We need to break, otherwise, it will go on forever
            break;
        }
    }

    return loopFound;
}

int main() {
    /*
     * Creating a Linked List of eight nodes having a loop at (node 3)
     *
     * HEAD-->1-->2-->3-->4-->5
     *                   ^    |
     *                   |    v
     *                   8<--7<--6
     */

    // Creating 8 independent nodes
    ListNode* nodeOne = new ListNode(1);
    ListNode* nodeTwo = new ListNode(2);
    ListNode* nodeThree = new ListNode(3);
    ListNode* nodeFour = new ListNode(4);
    ListNode* nodeFive = new ListNode(5);
    ListNode* nodeSix = new ListNode(6);
    ListNode* nodeSeven = new ListNode(7);
    ListNode* nodeEight = new ListNode(8);

    // Head node pointing to the first node of the linked list
    ListNode* nodeHead = nodeOne;

    // Creating a dependency in nodes by linking nodes to one another
    nodeOne->next = nodeTwo;
    nodeTwo->next = nodeThree;
    nodeThree->next = nodeFour;
    nodeFour->next = nodeFive;
    nodeFive->next = nodeSix;
    nodeSix->next = nodeSeven;
    nodeSeven->next = nodeEight;
    nodeEight->next = nodeThree; // This line creates the loop

    // Calling the function to check for a loop
    bool loopPresent = isLoopPresent(nodeHead);

    if (loopPresent) {
        std::cout << "Loop is Present" << std::endl;
    } else {
        std::cout << "No Loop Found" << std::endl;
    }

    // Clean up memory (free allocated nodes)
    delete nodeOne;
    delete nodeTwo;
    delete nodeThree;
    delete nodeFour;
    delete nodeFive;
    delete nodeSix;
    delete nodeSeven;
    delete nodeEight;

    return 0;
}
