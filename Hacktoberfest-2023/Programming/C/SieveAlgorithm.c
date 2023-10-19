/*
<----------------Sieve Algorithm-------------------------->
Sieve of Eratosthenes is used to get all prime number in a given range and is a very efficient algorithm.
*/

#include <stdio.h>

int main()
{
    int number,i,j;
    printf("Enter the number\n");
    scanf("%d",&number);

    int prime[number+1];
    for(i = 2; i<=number; i++)
        prime[i] = i;

    i = 2;
    while ((i*i) <= number)
    {
        if (prime[i] != 0)
        {
            for(j=2; j<number; j++)
            {
                if (prime[i]*j > number)
                    break;
                else
                    prime[prime[i]*j]=0;
            }
        }
        i++;
    }
    for(i = 2; i<=number; i++)
    {
        if (prime[i]!=0)
            printf("%d\n",prime[i]);
    }

    return 0;
}
