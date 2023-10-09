#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5
int size=0;

struct Node 
{
    int data;
    struct Node* next;
};
struct Node* top = NULL;
typedef struct Node* node;

void push() 
{
    int data;
    if (size == MAX_SIZE) 
    {
        printf("\nOverflow!\n");
        return;
    }

    printf("\nEnter data to push: ");
    scanf("%d",&data);
    node newNode = (node)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = top;
    top = newNode;
    size++;
}

void pop() 
{
    if (top == NULL) 
    {
        printf("\nUnderflow!\n");
        return;
    }
    
    printf("\nPopped Element: %d",top->data);
    node temp = top;
    top = top->next;
    free(temp);
}


void display() 
{
    if (top == NULL) 
    {
        printf("Underflow!\n");
        return;
    }

    printf("Stack elements: ");
    struct Node* current = top;
    while (current != NULL) 
    {
        printf("%d ",current->data);
        current=current->next;
    }
    printf("\n");
}

void main() 
{
    int choice;

    while (1) 
    {
        printf("\nStack Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid choice.\n");
        }
    }
}
