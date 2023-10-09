#include <stdio.h>
#define MAXSIZE 8
int stck[MAXSIZE], tos = -1, element;
void push()
{
    if (tos == MAXSIZE - 1)
    {
        printf("\nStack is full\n");
    }
    else
    {
        tos = tos + 1;
        printf("Enter a value to push: ");
        scanf("%d", &element);
        stck[tos] = element;
        printf("\nValue is pushed\n");
    }
}
void pop()
{
    if (tos == -1)
    {
        printf("\nStack is empty\n");
    }
    else
    {
        printf("\n%d is popped from the stack\n", stck[tos]);
        tos = tos - 1;
    }
}
void display()
{
    int i;
    for (i = tos; i >= 0; i--)
    {
        printf("%d\n", stck[i]);
    }
}
int main()
{
    int choice;
    printf("\n******Stack Operations******\n");
    printf("1.Push\n2.Pop\n3.Display\n4.Exit\n");
    while (choice != 4)
    {
        printf("Enter your choice in number: ");
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
            printf("\nProgram is exited\n");
            break;
        default:
            printf("\nPlease enter a valid choice\n");
        }
    }
    return 0;
}