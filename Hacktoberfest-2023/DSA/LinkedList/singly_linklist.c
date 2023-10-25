#include <stdio.h>
#include <stdlib.h>


struct Node{
	int data;
	struct Node *addr;	
}*start,*curr,*prev;

void create(int);
void display();
void insertFirst(int);
void insertMiddle(int,int);
void deleteFirst();
void deleteMiddle(int);
void serachNode(int);
void reverse();

int main() {
	int n,ch,loc,c;
	start=NULL;
	do{
		printf("\n1.create Node \n2.Display node \n3.Insert at first \n4.Insert at middle \n5.Delete at first \n6.Delete at middle \n7.search node \n8.Reverse linke list");
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("\nEnter the any number:");
				scanf("%d",&n);
				create(n);
				break;
			case 2:
				display();
				break;
			case 3:
				printf("\nEnter the new node at first :");
				scanf("%d",&n);
				insertFirst(n);
				break;
			case 4:
				printf("\nEnter the location to insert new node :");
				scanf("%d",&loc);
				printf("\nEnter the new node  :");
				scanf("%d",&n);
				insertMiddle(n,loc);
				break;
			case 5:
				deleteFirst();
				break;
			case 6:
				printf("\nEnter the location to delete  node :");
				scanf("%d",&loc);
				deleteMiddle(loc);
				break;	
			case 7:
				printf("\nEnter the  node that you search :");
				scanf("%d",&n);
				searchNode(n);
				break;
			case 8:
				reverse();
				break;
		}

		printf("\nDo you want to continue then press 1 :");
		scanf("%d",&c);
		if(c!=1){
			break;
		}
	}while(c==1);
	return 0;
}

void create(int n){
	
	struct Node *newNode;
	newNode = malloc(sizeof(struct Node));
	newNode->data=n;
	newNode->addr=NULL;
	if(start==NULL){
		start=newNode;
	}
	else{
		curr=start;
		while(curr->addr!=NULL){
			curr=curr->addr;
		}
		curr->addr=newNode;
	}
}
//insert at beginning 
void insertFirst(int n){
	struct Node *newNode;
	newNode = malloc(sizeof(struct Node));
	newNode->data=n;
	newNode->addr=start;
	start=newNode;
	printf("\nNode is inserted...");
}

void insertMiddle(int n,int loc){
	
	struct Node *newNode;
	newNode = malloc(sizeof(struct Node));
	newNode->data=n;
	int cnt;
	cnt=1;
	curr=start;
	while(cnt<loc){
		curr=curr->addr;
		cnt++;
	}
	newNode->addr=curr->addr;
	curr->addr=newNode;
	printf("\nNode is inserted...");	
}

void deleteFirst(){
	curr=start;
	start=start->addr;
	curr->addr=NULL;
	free(curr);
	printf("\nNode is deleted...");
}

void deleteMiddle(int loc){
	struct Node *prev;
	int cnt;
	cnt=1;
	curr=start;
	prev=NULL;
	while(cnt<loc){
		prev=curr;
		curr=curr->addr;
		cnt++;
	}
	prev->addr=curr->addr;
	free(curr);
	printf("\n Node is deleted");	
}
	

void display()
{
	if(start==NULL)
	{
		printf("\nLinked list is empty");
	}
	else
	{
		curr=start;
		while(curr!=NULL)
		{
			printf("%d| %u| -->",curr->data,curr->addr);
			curr=curr->addr;
		}
	}
}

void searchNode(int n){
	int cnt,flag;
	curr=start;
	cnt=1;
	while(curr!=NULL){
		if(curr->data==n){
			flag=1;
			break;
		}
		curr=curr->addr;
		cnt++;
	}
	if(flag==1){
		printf("Element found at %d location :",cnt);
	}
	else{
		printf("Element not found");
	}
}

void reverse(){
	struct Node *ptr1 = NULL, *ptr2 = NULL, *ptr3 = NULL;
	ptr1=start;
	ptr2=ptr1->addr;
	ptr1->addr=NULL;
	
	while(ptr2!=NULL){
		ptr3= ptr2->addr;
		ptr2->addr=ptr1;
		ptr1=ptr2;
		ptr2=ptr3;
	}
	start=ptr1;
	printf("reverse done");
}
