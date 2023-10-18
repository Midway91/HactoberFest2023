// this is the simplest code build by myself.
#include <stdio.h>
#include <stdlib.h>
struct cll
{
    int data;
    struct cll *next;
} *head;

int nodes()
{
    int count = 0;
    struct cll *ptr;
    ptr = head;
    if (head == NULL)
    {
        return 0;
    }
    else
    {
        while (ptr->next != head)
        {
            ptr = ptr->next;
            count++;
        }
        return count + 1;
    }
}

void insert_node()
{
    int data, pos;
    int p = nodes();
    scanf("%d", &pos);
    struct cll *ptr, *newnode;
    newnode = (struct cll *)malloc(sizeof(struct cll));
    if (pos < 1 || pos > p + 1)
    {
        printf("Position does not exist - Cannot insert into CLL\n");
    }
    else
    {
        scanf("%d", &data);
        newnode->data = data;
        if (pos == 1)
        {
            if (head == NULL)
            {
                head = newnode;
                newnode->next = head;
            }
            else
            {
                ptr = head;
                while (ptr->next != head)
                {
                    ptr = ptr->next;
                }
                newnode->next = head;
                head = newnode;
                ptr->next = newnode;
            }
        }
        else if (pos == p + 1)
        {
            ptr = head;
            while (ptr->next != head)
            {
                ptr = ptr->next;
            }
            // ptr = ptr->next;
            ptr->next = newnode;
            newnode->next = head;
        }
        else
        {
            ptr = head;
            for (int i = 1; i < p; i++)
            {
                ptr = ptr->next;
            }
            newnode->next = ptr->next;
            ptr->next = newnode;
        }
    }
}

void delete_node()
{
    struct cll *ptr, *ptr1;
    int pos;
    scanf("%d", &pos);
    int p = nodes();
    if (head == NULL)
    {
        printf("Position does not exist - Cannot delete from CLL\n");
    }
    else
    {
        if (pos < 1 || pos > p)
        {
            printf("Position does not exist - Cannot delete from CLL\n");
        }
        else
        {
            if (pos == 1)
            {
                if (p == 1)
                {
                    printf("Deleted element from CLL is %d\n", head->data);
                    free(head);
                }
                else
                {
                    ptr = head;
                    while (ptr->next != head)
                    {
                        ptr = ptr->next;
                    }
                    printf("Deleted element from CLL is %d\n", head->data);
                    head = head->next;
                    ptr->next = head;
                }
            }
            else if (pos == p)
            {
                ptr = head;
                while (ptr->next != head)
                {
                    ptr1 = ptr;
                    ptr = ptr->next;
                }
                ptr1->next = head;
                printf("Deleted element from CLL is %d\n", ptr->data);
                free(ptr);
            }
            else
            {
                int num = 1;
                ptr = head;
                while (pos != num)
                {
                    ptr1 = ptr;
                    ptr = ptr->next;
                    num++;
                }
                ptr1->next = ptr->next;
                printf("Deleted element from CLL is %d\n", ptr->data);
                free(ptr);
            }
        }
    }
}

void search()
{
    struct cll *ptr;
    int element;
    scanf("%d", &element);
    if (head == NULL)
    {
        printf("cll is empty\n");
    }
    else
    {
        ptr = head;
        while ((ptr->data != element) && (ptr->next != head))
        {
            ptr = ptr->next;
        }
        if (ptr->data == element)
        {
            printf("%d is found in CLL\n", element);
        }
        else
        {
            printf("%d is not found in CLL\n", element);
        }
    }
}

void display()
{
    struct cll *ptr;
    if ((head == NULL) || (head->data == 0))
    {
        printf("Empty CLL - Cannot display\n");
    }
    else
    {
        ptr = head;
        while (ptr->next != head)
        {
            printf("%d ->", ptr->data);
            ptr = ptr->next;
        }
        printf("%d ->\n", ptr->data);
    }
}

int main()
{
    int option;
    while (1)
    {
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            insert_node();
            break;

        case 2:
            delete_node();
            break;

        case 3:
            display();
            break;

        case 4:
            search();
            break;

        case 5:
            exit(0);

        default:
            printf("enter valid choice\n");
        }
    }
}