#include<stdio.h>
#include<stdlib.h>

typedef struct polynomial
{
	int coef;
	int expo;
	struct polynomial *next;
}poly;

poly *create_poly(poly *);
poly *insert_poly_node(poly *, int, int);
void show_poly(poly *);

int main() {
    int choice;
    do{
        poly *poly1;
        
 		poly1 = NULL;
 		
        printf("\nCreate 1st expression\n");
        poly1 = create_poly(poly1);
        printf("\nDisplay the 1st expression:\n");
        show_poly(poly1);
        
        printf("\nDo you want to show more polynomials?\n");
		printf("Enter 1 for Yes, 0 for No: ");
        scanf("%d", &choice);
    }while(choice);
    return 0;
}

poly *create_poly(poly *start)
{
	int i,n,ex,co;
	printf("How many terms u want to enter : ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("Enter coeficient for term %d : ",i);
		scanf("%d",&co);
		printf("Enter exponent for term %d : ",i);
		scanf("%d",&ex);
		start = insert_poly_node(start, co, ex);
	}
	return(start);
}

poly *insert_poly_node(poly *start, int co, int ex)
{
	poly *ptr, *tmp;
	tmp = (poly *)malloc(sizeof(poly));
	tmp->coef = co;
	tmp->expo = ex;
	tmp->next = NULL;

	if(start == NULL)
		start = tmp;
	else
	{
		ptr = start;
		while(ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = tmp;
	}
	return(start);
}

void show_poly(poly *ptr)
{
	if(ptr==NULL)
	{
		printf("Empty\n");
		return;
	}
	while(ptr->next != NULL)
	{
		printf("(%dx^%d) + ", ptr->coef,ptr->expo);
		ptr=ptr->next;
	}
	printf("(%dx^%d)", ptr->coef,ptr->expo);
	printf("\n");
}

