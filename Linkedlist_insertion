#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void LinkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    }
}


struct Node* insertAtFirst(struct Node *head,int data)
{
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node*));
    ptr->next=head;
    ptr->data= data;
    return ptr;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;


    // Allocate memory for nodes int the linked list in heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));


    // Link first and second nodes
    head->data = 7;
    head->next = second;

   // Link the second and third node
    second->data = 11;
    second->next = third;


    //Link the Third and fourth node
    third->data = 41;
    third->next = fourth;

 
    // Terminating the list at the fourth node
    fourth->data = 66;
    fourth->next = NULL;

    LinkedListTraversal(head);
    head = insertAtFirst(head,56);
    LinkedListTraversal(head);


    return 0;
}
