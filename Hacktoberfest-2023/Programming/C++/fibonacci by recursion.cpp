# include<stdio.h>
int factorial(int n){
	if(n==0)
	{
		return 1;
		
	}
	else{
		return n*factorial(n-1);
	}
}
int fibonacci (int n)
{
	if(n==0){
		return 0;
		
	} else if (n==1){return 1;
	
	} else {
		return (fibonacci(n-1)+fibonacci(n-2));
		
	}
}
int main()
{
	int n=5;
	int i;
	printf("Factorial of %d: %d\n",n,factorial(n));
	printf("Fibonacci of %d: ",n);
	
	for(i=0;i<n;i++){
		printf("%d",fibonacci(i));
	}
}
