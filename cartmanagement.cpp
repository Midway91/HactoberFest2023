// you can add and remove items from cart and display which is added/removed

#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    string item;
    Node* next;

    Node(string item) {
        this->item = item;
        next = nullptr;
    }
};

class ShoppingCart {
private:
    Node* head;
    vector<string> addedItems;
    vector<string> removedItems;

public:
    ShoppingCart() {
        head = nullptr;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    void addItem(string item) {
        Node* newNode = new Node(item);
        newNode->next = head;
        head = newNode;
        addedItems.push_back(item);
        cout << item << " has been added to the cart." << endl;
    }

    void removeItem(string item) {
        if (head == nullptr) {
            cout << "Cart is empty. Cannot remove " << item << "." << endl;
            return;
        }

        if (head->item == item) {
            Node* temp = head;
            head = head->next;
            delete temp;
            removedItems.push_back(item);
            cout << item << " has been removed from the cart." << endl;
            return;
        }

        Node* current = head;
        while (current->next != nullptr && current->next->item != item) {
            current = current->next;
        }

        if (current->next == nullptr) {
            cout << item << " is not in the cart." << endl;
        } else {
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
            removedItems.push_back(item);
            cout << item << " has been removed from the cart." << endl;
        }
    }

    void displayAddedRemovedItems() {
        cout << "Added Items: ";
        for (const string& item : addedItems) {
            cout << item << " ";
        }
        cout << endl;

        cout << "Removed Items: ";
        for (const string& item : removedItems) {
            cout << item << " ";
        }
        cout << endl;
    }
};

int main() {
    ShoppingCart cart;

    while (true) {
        cout << "Options:" << endl;
        cout << "1. Add item to cart" << endl;
        cout << "2. Remove item from cart" << endl;
        cout << "3. Display added/removed items" << endl;
        cout << "4. Quit" << endl;
        int choice;
        cin >> choice;

        if (choice == 1) {
            cout << "Enter item name: ";
            string item;
            cin >> item;
            cart.addItem(item);
        } else if (choice == 2) {
            cout << "Enter item name to remove: ";
            string item;
            cin >> item;
            cart.removeItem(item);
        } else if (choice == 3) {
            cart.displayAddedRemovedItems();
        } else if (choice == 4) {
            break;
        }
    }

    return 0;
}
