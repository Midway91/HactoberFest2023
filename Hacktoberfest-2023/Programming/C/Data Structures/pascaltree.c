#include<stdio.h>

int factorial(int);

int ncr(int,int);

int main()
{
	int n,i,j;
	printf("Enter the number of rows: ");
	scanf("%d",&n);
    for (i = 1; i <= n; i++) 
    {
        for(j=1;j<=n-i;j++)
        {
        	printf(" ");
        }
        for(j=1;j<=i;j++)
        {
        	printf("%d ",ncr(i,j-1));
        }
        printf("\n");
    }
    return 0;
}

int factorial(int n)
{
	int num=1;
	for(int i=2;i<=n;i++)
	{
		num*=i;
	}
	return num;
}

int ncr(int n,int r)
{
	int num=factorial(n)/(factorial(r)*factorial(n-r));
	return num;
}
