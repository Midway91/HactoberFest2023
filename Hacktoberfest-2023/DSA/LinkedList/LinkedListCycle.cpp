#include <iostream>
using namespace std;

class LinkedList
{
private:
    class Node
    {
    public:
        string data;
        Node *next;

        Node(string data) : data(data), next(nullptr) {}
    };

    Node *head;
    int size;

public:
    LinkedList() : head(nullptr), size(0) {}

    void printlist()
    {
        if (head == nullptr)
        {
            cout << "List is Empty" << endl;
            return;
        }
        Node *currNode = head;
        while (currNode != nullptr)
        {
            cout << currNode->data << " -> ";
            currNode = currNode->next;
        }
        cout << "null" << endl;
    }

    void addfirst(string data)
    {
        Node *newnode = new Node(data);
        newnode->next = head;
        head = newnode;
        size++;
    }

    void addlast(string data)
    {
        Node *newnode = new Node(data);
        if (head == nullptr)
        {
            head = newnode;
        }
        else
        {
            Node *lastnode = head;
            while (lastnode->next != nullptr)
            {
                lastnode = lastnode->next;
            }
            lastnode->next = newnode;
        }
        size++;
    }

    void deletefirst()
    {
        if (head == nullptr)
        {
            cout << "List is already Empty" << endl;
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
        size--;
    }

    void deletelast()
    {
        if (head == nullptr)
        {
            cout << "List is Empty" << endl;
            return;
        }

        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
        }
        else
        {
            Node *currNode = head;
            while (currNode->next->next != nullptr)
            {
                currNode = currNode->next;
            }
            delete currNode->next;
            currNode->next = nullptr;
        }
        size--;
    }

    int getSize()
    {
        return size;
    }

    /**
     * Determines whether the linked list has a cycle.
     *
     * @return true if the linked list has a cycle, false otherwise
     */
    bool hasCycle()
    {
        if (head == nullptr || head->next == nullptr)
        {
            return false;
        }

        Node *slow = head;
        Node *fast = head;

        while (slow != nullptr && fast != nullptr)
        {
            fast = fast->next;

            if (fast != nullptr)
            {
                fast = fast->next;
            }

            slow = slow->next;

            if (fast == slow)
            {
                return true;
            }
        }

        return false;
    }

    ~LinkedList()
    {
        while (head != nullptr)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main()
{
    LinkedList list;
    list.addfirst("Dev");
    list.addfirst("Datir");
    list.printlist();
    list.addlast("From");
    list.addlast("Amravati");
    list.deletefirst();
    list.deletelast();
    list.deletelast();
    list.addlast("Datir");
    list.printlist();
    cout << "Size: " << list.getSize() << endl;

    if (list.hasCycle())
    {
        cout << "The linked list has a cycle." << endl;
    }
    else
    {
        cout << "The linked list does not have a cycle." << endl;
    }

    return 0;
}
