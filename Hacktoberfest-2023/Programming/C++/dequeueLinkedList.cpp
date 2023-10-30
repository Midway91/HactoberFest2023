#include<iostream>
#include<cstdlib>
using namespace std;
void create();
void display();
void insertbegin();
void insertend();
void deletebegin();
void deleteend();

class node{
public:

	int info;
	node *next;
	node *prev;
};

node *start=NULL;
node *last=NULL;
int main()
{
	
int c;
while(1)
{
	cout << "\nselect choice" << endl;
	cout << "\n1. create \n2. display \n3. insertbegin\n4. insertend\n5. deletebegin\n6. deleteend\n7. exit" << endl;
	cin>>c;
	switch(c)
	{
		case 1:create();
		break;
		case 2:display();
		break;
		case 3:insertbegin();
		break;
		case 4:insertend();
		break;
		case 5:deletebegin();
		break;
		case 6:deleteend();
		break;
		case 7:exit(0);
		break;
		default:cout<< "wrong choice";
	}
}
}

void create()
{

node *tmp,*ptr,*previ;
tmp = new node();
cout << "enter new number" << endl;
cin>>tmp->info;
tmp->next=NULL;
if (start==NULL)
{
	start=last=tmp;
	start->next=NULL;
	last->prev=NULL;
}
else {
	ptr = start;
	while(ptr->next!=NULL)
	{
		previ=ptr;
		ptr=ptr->next;
	}

	ptr->next =tmp;
	ptr->prev=previ;

	last=tmp;
}
}

void display()
{
	node *ptr;
	cout << "linked list \t";
	for (ptr=start;ptr!=NULL;ptr= ptr->next)
		cout<<ptr->info << "\t";
	cout<<"\nstart\t" << start->info;
	cout <<"\nlast\t" << last->info;
}


void insertbegin()
{
	node *nn;
	nn = new node();
	cout << "enter new number" << endl;
	cin >> nn->info;
	nn->next=start;
	start->prev=nn;
	start=nn;
}


void insertend()
{
	node *nn,*tmp;
	nn = new node();
	cout << "enter new number\n";
	cin >> nn->info;
	tmp = start;
	while(tmp->next!=NULL)
	{
		tmp = tmp->next;

	}
	tmp->next=nn;
	nn->next=NULL;
	nn->prev=tmp;
	last=nn;
}

void deletebegin()
{
	node *nn,*tmp;
	tmp = start;
	start->next->prev=start->prev;
	start=start->next;
	start->prev=NULL;
}


void deleteend()
{
	node *nn,*tmp;
	last->prev->next=NULL;
	last=last->prev;

}
