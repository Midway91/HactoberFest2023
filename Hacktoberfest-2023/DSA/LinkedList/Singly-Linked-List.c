#include<stdio.h>
#include<stdlib.h>

// creating a node
struct Node
{
    int data;
    struct Node *next;
}*first=NULL,*second=NULL,*third=NULL;

// create a new node and making linked list by joining nodes
void create(int A[], int n)
{
    int i;
    struct Node *t,*last;
    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(i=1; i<n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

// traversing/displaying linked list 
void Display(struct Node *p)
{
    while(p!=NULL)
    {
        printf("%d ", p->data);
        p=p->next;
    }
}

// traversing/displaying linked list using recursion
void RDisplay(struct Node *p)
{
    if(p!=NULL)
    {
        printf("%d ", p->data);
        RDisplay(p->next);
    }
}

// traversing/displaying linked list in reverse order by using recursion
// just switching the position of recursive function
void DisplayR(struct Node *p)
{
    if(p!=NULL)
    {
        DisplayR(p->next);
        printf("%d ", p->data);
    }
}

// counting the no. of elements in the linked list
int count(struct Node *p)
{
    int l = 0;
    while(p)
    {
        l++;
        p = p->next;
    }
    return l;
}

// counting the no. of elements in the linked list using recursion
int Rcount(struct Node *p)
{
    if(p!=NULL)
        return Rcount(p->next)+1;
    else
        return 0;
}

// Sum of all the elements in the linked list
int sum(struct Node *p)
{
    int sum=0;
    
    while(p!=NULL)
    {
        sum+=p->data;
        p=p->next;
    }
    return sum;
}
// Sum of all the elements in the linked list using recursion
int Rsum(struct Node *p)
{
    if(p==NULL) 
        return 0;
    else
        return Rsum(p->next)+p->data;
}

// Maximum number in a linked list
int Max(struct Node *p)
{
    int max = -65535 ;

    while(p)
    {
        if (p->data > max);
            max = p->data;
        p=p->next;
    }
    return max;
}

// Maximum number in a linked list using recursion
int RMax(struct Node *p)
{
    int x = 0;
    int max = -65535;
    if(p==0)
        return max;
    x = RMax(p->next);
    if (x > p->data)
        return x;
    else 
        return p->data;
}

// Linear Search in a linked list
struct Node * LSearch(struct Node *p, int key)
{
    while (p != NULL)
    {
        if (key == p->data)
            return p;
        p = p->next;
    }
    return NULL;
}

// Linear Search in a linked list using recursion
struct Node * RSearch(struct Node *p, int key)
{
    if(p == NULL)
        return NULL;
    if(key==p->data)
        return p;
    return RSearch(p->next,key);
}


// Insertion in a linked list
void Insert(struct Node *p, int index, int x)
{
    struct Node *t;
    if(index < 0 || index > count(p))     // to check whether given index is valid or not
        return;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data = x;

    if(index==0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for(int i = 0; i < index-1; i++)
            p = p->next;
        t->next = p->next;
        p->next = t;
    }
}

// Insertion in a Sorted linked list
void SortedInsert(struct Node *p,int x)
{
    struct Node *t,*q=NULL;

    t =(struct Node*)malloc(sizeof(struct Node));
    t->data=x;
    t->next=NULL;

    if(first==NULL)
        first=t;
    else
    {
        while(p && p->data<x)
        {
            q=p;
            p=p->next;
        }
        if(p==first)   // the element we are inserting is the smallest element
        {
            t->next = first;
            first=t;
        }
        else
        {
            t->next =q->next;
            q->next =t;
        }
    } 
}

// Deletion in a linked list 
int Delete(struct Node *p, int index)
{
    struct Node *q = NULL;
    int x = -1,i;

    if (index < 1 || index > count(p))
    return -1;
    if(index == 1)
    {
        q = first;
        x = first->data;
        first=first->next;
        free(q);
        return x;
    }
    else
    {
        for (i = 0; i < index-1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next=p->next;
        x=p->data;
        free(p);
        return x; 
    }
}

// Checking whether the linked list is sorted or not
int isSorted(struct Node *p)
{
    int x = -65536;

    while(p!=NULL)
    {
        if(p->data<x)
            return 0;
        x = p->data;
        p = p->next;
    }
    return 1;
}

// Removing duplicates from a Sorted Linked List
void RemoveDuplicate(struct Node *p)
{
    struct Node *q = p->next;

    while(q!=NULL)
    {
        if(p->data!=q->data)
        {
            p = q;
            q=q->next;
        }
        else
        {
            p->next = q->next;
            free(q);
            q = p->next;
        }
    }
}

//Reversing a linked list 
void Reverse1(struct Node *p)   // Reversing elements by storing the elements in an array and then return the elements of the array backwards
{
    int *A, i=0;
    struct Node *q=p;
    A=(int *)malloc(sizeof(int)*count(p));

    while(q!=NULL)
    {
        A[i]=q->data;
        q=q->next;
        i++;
    }
    q=p;
    i--;
    while(q!=NULL)
    {
        q->data=A[i];
        q=q->next;
        i--;
    }
}

//Reversing a linked list 
void Reverse2(struct Node *p)    //Reversing links of a node (This method is preferable because we don't want to change the data of the respective node). This method used sliding pointers.
{
    struct Node *q=NULL, *r=NULL;

    while(p!=NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next=r;
    }
    first = q;
}

// Reversing a linked list using recursion
void Reverse3(struct Node *q, struct Node *p)
{
    if(p)
    {
        Reverse3(p,p->next);
        p->next=q;
    }
    else
    first = q;
}

// create a new node and making linked list by joining nodes
void create2(int A[], int n)
{
    int i;
    struct Node *t,*last;
    second=(struct Node *)malloc(sizeof(struct Node));
    second->data=A[0];
    second->next=NULL;
    last=second;

    for(i=1; i<n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

//Concatenate the linked list
void Concat(struct Node *p, struct Node *q)
{
    third=p;

    while(p->next!=NULL)
        p=p->next;
    p->next=q;
}

//Merging of two linked lists
void Merge(struct Node *p,struct Node *q)
{
    struct Node *last;
    if(p->data < q->data)
    {
        third=last=p;
        p=p->next;
        third->next=NULL;
    }
    else
    {
        third=last=q;
        q=q->next;
        third->next=NULL;
    }
    while(p && q)
    {
        if(p->data < q->data)
        {
            last->next=p;
            last=p;
            p=p->next;
            last->next=NULL;
        }
        else
        {
            last->next=q;
            last=q;
            q=q->next;
            last->next=NULL;
        }
    }
    if(p)
        last->next=p;
    if(q)   
        last->next=q;
}

// Checking Loop for Linked List
int isLoop(struct Node *f)
{
    struct Node *p,*q; 
    p=q=f;

    do
    {
        p=p->next;
        q=q->next;
        q=q?q->next:q;
    }while(p && q && p!=q);
    if(p==q)    
        return 1;
    else
        return 0;
}

// main function
int main()
{
    int A[]={10,20,30,40,50};
    // int B[]={1,2,3,4,5};
    create(A,(sizeof(A)/sizeof(A[0])));
    // create2(B,(sizeof(B)/sizeof(B[0])));

    Display(first);
    // printf("\n");
    // Display(second);
    // printf("\n");
    // RDisplay(first);
    // printf("\n");
    // DisplayR(first);
    printf("\nLength is %d",count(first));
    // printf("\nLength is %d",Rcount(first));
    printf("\nSum is %d",sum(first));
    // printf("\nSum is %d",Rsum(first));
    printf("\nMax is %d",Max(first));
    // printf("\nMax is %d",RMax(first));

    // struct Node *temp1, *temp2;

    // temp1 = LSearch(first, 15);
    // if(temp1) 
    //     printf("\nKey is found %d", temp1->data);
    // else 
    //     printf("\nKey is not found");

    //     temp2 = RSearch(first, 15);
    // if(temp2) 
    //     printf("\nKey is found %d", temp2->data);
    // else 
    //     printf("\nKey is not found");
    
    
    // Insert(first,3, 12);
    // Insert(first,0,1);
    // printf("\n");
    // Display(first);
    // SortedInsert(first,18);
    
    // printf("\nDeleted element is %d\n",Delete(first,4));


    // if(isSorted(first))
    // {
    //     printf("\nSorted");
    // }
    // else
    // {
    //     printf("\nNot Sorted");
    // }

    // RemoveDuplicate(first);

    // Reverse1(first);
    // Reverse2(first);
    // Reverse3(NULL,first);  

    // printf("\n");
    // Display(first);

    // Concat(first,second);

    // Merge(first,second);

    // printf("\n");
    // Display(third);

    // Checking Loop for Linked list 
    // struct Node *t1,*t2;

    // int A[] = {10,20,30,40,50};
    // create(A,5);

    // t1=first->next->next;
    // t2=first->next->next->next->next;
    // t2->next=t1;

    // printf("%d\n",isLoop(first));
    
    return 0;
}