#include<stdio.h>
int main()
{
     int n, reverse = 0, temp;
     printf("enter the number :");
     scanf("%d",&n);
     temp = n;
     while(temp!=0)
     {        
        reverse = reverse*10 + temp%10;        
        temp=temp/10;    
    }
     if(reverse == n)
     {
        printf("The given number is a palindrome");
     }
     else
     {
        printf("The given number is not a palindrome");
     }
 }