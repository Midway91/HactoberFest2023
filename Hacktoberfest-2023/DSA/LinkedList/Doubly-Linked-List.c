#include<stdio.h>
#include<stdlib.h>

// structuring the node
struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
}*first=NULL;

// create a linked list
void create(int A[], int n)
{
    struct Node *t,*last;
    int i;

    first=(struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->prev = first->next = NULL;
    last=first;

    for(i=1;i<n;i++)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next = last->next;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

// Display
void Display(struct Node *p)
{
    while(p)
    {
        printf("%d ", p->data);
        p=p->next;
    }
    printf("\n");
}

// Length of the linked list
int Length(struct Node *p)
{
    int len = 0;

    while(p)
    {
        len++;
        p=p->next;
    }
    return len;
}

// Insertion 
void Insert(struct Node *p,int index,int x)
{
    struct Node *t;
    int i;
    if(index < 0 || index > Length(p))
    return;

    if(index==0)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=x;
        t->prev=NULL;
        t->next=first;
        first->prev=t;
        first=t;
    }
    else
    {
        for(i=0;i<index-1;i++)
            p=p->next;
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=x;

        t->prev=p;
        t->next=p->next;
        if(p->next)
             p->next->prev=t;
        p->next=t;     
    }
}
 
// Deletion 
int Delete(struct Node *p, int index)
{
    int x = -1,i;

    if(index < 1 || index > Length(p))
    return -1;

    if(index==1)
    {
        first=first->next;
        if(first)
            first->prev=NULL;

        x=p->data;
        free(p);
    }
    else
    {
        for(i=0;i<index-1;i++)
            p=p->next;
        p->prev->next=p->next;
        if(p->next)
            p->next->prev=p->prev;
        x=p->data;
        free(p);
    }
    return x;
}

// Reversing a doubly linked list
void Reverse(struct Node *p)
{
    struct Node *temp;

    while(p!=NULL)
    {
        temp=p->next;
        p->next=p->prev;
        p->prev=temp;
        p=p->prev;
        if(p!=NULL && p->next==NULL)
            first = p;
    }
}

int main()
{
    int A[] = {10,20,30,40,50};
    create(A,(sizeof(A)/sizeof(A[0])));

    printf("\nLength is %d\n", Length(first));

    Display(first);

    Insert(first,2,25);
    Insert(first,0,5); 

    Display(first);

    printf("Deleted element is %d\n",Delete(first,4));
    printf("Deleted element is %d\n",Delete(first,1));

    Display(first);

    Reverse(first); 
    
    Display(first);

    return 0;
}