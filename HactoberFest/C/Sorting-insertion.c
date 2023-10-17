#include<stdio.h>
#include<stdlib.h>
void main()
{
    int i,j,m,x,choice,temp;
    printf("SORTING USING INSERTION METHOD\n");
    printf("\nEnter 1 for Sorting in Ascending order\nEnter 2 for Sorting in Descending Order\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);
    printf("Enter the size of the array: ");
    scanf("%d",&x);
    int a[x];
    printf("Enter the numbers to be sorted in the array below:-\n");
    for(i=0;i<x;i++)
        scanf("%d",&a[i]);
    for (i = 0; i < x - 1; i++) 
    {
      m = i;
      for (j = i + 1; j < x; j++)
       {
        if(choice==1)
        {
         if (a[j] < a[m])
            m = j;
        }
        else if(choice==2)
        {
            if (a[j] > a[m])
                m = j;
        }
        else
        {
            printf("Invalid Input");
            exit(1);
        }
      }
      temp = a[m];
      a[m] = a[i];
      a[i] = temp;
   }
    if(choice==1)
    {
    printf("The sorted array in ascending order: ");
     for(i=0;i<x;i++)
        printf("%d ",a[i]);
    }
    if(choice==2)
    {
    printf("The sorted array in descending order: ");
     for(i=0;i<x;i++)
        printf("%d ",a[i]);
    }
}