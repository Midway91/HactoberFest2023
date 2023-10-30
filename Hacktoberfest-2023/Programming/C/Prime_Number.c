#include<stdio.h>
void main()
{
  /* a= variable which will store input number
      count= 0 (it is a variable initialized with value 0 */
  int a,count=0;
  printf("Enter a number= ");
  scanf("%d",&a);

/* Procedure to find whether the entered number is prime or not?
   loop will run from 1 to a (till entered number)
   example: a=6
   then loop will run from 1 to 6. */ 
  for(int i=1;i<=a;i++)
  {

    // if entered number gives reminder 0 on dividing with 1 to a one by one then count will increment each time.
    if(a%i==0)
    {
      count=count+1;
    }
  }

// if number is divisible by 1 and itself only means count will equal to 2 only. Then it is a prime number.
if(count==2)
{
  printf("%d is a prime number.",a);
}
else
{
  printf("%d is not a prime number.",a);
}
}
