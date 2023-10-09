#include<stdio.h>
// long int multiplyNumbers(int n);
int main() {
    int n;
    long int factorial=1;
    printf("Enter a positive integer: ");
    scanf("%d",&n);
    for(int i=1; i<=n; i++) {
        factorial*= i;
    }
    printf("Factorial of %d = %ld", n, factorial);
    return 0;
}

// long int multiplyNumbers(int n) {
//     if (n>=1)
//         return n*multiplyNumbers(n-1);
//     else
//         return 1;
// }
