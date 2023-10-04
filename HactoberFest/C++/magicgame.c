/*
Nmae:Akash Singh
github: https://github.com/Akashsnar

The following (game)code help to identify whether user input magic matrix or not
also provide undo option 

magic matrix: sum of its row, column and dignol equals 

Testcases are at the end
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<unistd.h>
#include<time.h>
#include<string.h>
int n1=0;
int multiplication(int x, int y);
int magicgame(int n1);
int display(int r, int c, int **a);
int display(int r, int c, int **a){
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%2d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
int magic(int r, int c, int a[r][c], int sum){

    int k1=0, k2=0, k3=0;
 for (int i = 0; i < r; i++)
{
        for (int j = 0; j < c; j++)
    {
        k1=k1+a[i][j];
        k2=k2+a[j][i];
        if (i==j)
        {
            k3=k3+a[i][j];
        }
    }
    if (k1!=sum || k2!=sum)
    { printf("not magic\n");
        return 0;
    }
    k2=0;
    k1=0;
    
}
if (k3!=sum)
    { printf("not magic matrix\n");
        return 0;
    }
printf("magic matrix\n");
return 1;
}

int magicgame(int n1){
    int **a, b[n1][n1];
    a=(int **)malloc(n1*sizeof(int *));
    for (int i = 0; i < n1; i++)
    {
        a[i]=(int *)malloc(n1*sizeof(int));
    }

for (int i=0; i < n1; i++)
{
    for (int j=0; j < n1; j++)
    {a[i][j]=0;
    }
}
    char k;
for (int i=0; i < n1; i++)
{
    for (int j=0; j < n1; j++)
    {
        //  printf("%d %d\n", i, j);
        fflush(stdin);
        scanf("%c", &k);
        if (k>='0' && k<='9')
        {
            a[i][j]=k-'0';
            b[i][j]=a[i][j];
            display(n1, n1, a);
        }
        else if (k=='p' && j!=0)
        {
            a[i][j-1]=0;
            display(n1, n1, a);
            j=j-2;
        }
        else
        {
             a[i-1][n1-1]=0;
            display(n1, n1, a);
            i=i-1;
            j=n1-2;
        }
    }
}
  int sum=0;
  for (int i = 0; i < n1; i++)
  {
   sum=sum+b[0][i];
  }
  
   sum = magic(n1, n1, b, sum);
   if (sum==1)
   {
       printf("you win!! \n");
   }
   else  
   printf("you loss \n");
}
int multiplication(int x, int y){
     //printf("rjirjif");
    int l= y - x + 1;
    int n[l][l];
    for (int i = 0; i < l; i++)
    {
         for (int j = 0; j < l; j++)
    {
        n[i][j]=(i+x)*(j+x);
        printf("%2d ", n[i][j]);
    }
    printf("\n");
    }
    
}
int main()
{

int s, k;
printf("Welcome in the game enter size of matrix\n");
scanf("%d", &n1);
printf("Enter your numbers(1 digit at a time follwing enter) in matrix and press p for undo\n");
magicgame(n1);
    return 0;
}

/*Test cases-1
3
4	
9	
2
3	
5	
7
8	
1	
6

Test case -2
3
1 
2 
9
5 
7 
8
2 
0 
6

Test case -3
4
7	
1	
4	
6
2	
8	
5	
3
5	
3	
2	
8
4	
6	
7	
1


*/