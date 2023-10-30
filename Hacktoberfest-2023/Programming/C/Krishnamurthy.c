#include <stdio.h>

//here is the Function to calculate the factorial of a number
int factorial(int num) {
    if (num == 0 || num == 1) {
        return 1;
    } else {
        return num * factorial(num - 1);
    }
}

// here is the Function to check if a number is a Krishnamurthy number
int isKrishnamurthy(int num) {
    int originalNum = num;
    int sum = 0;

    while (num > 0) {
        int digit = num % 10;
        sum += factorial(digit);
        num /= 10;
    }

    return (sum == originalNum);
}

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (isKrishnamurthy(num)) {
        printf(" %d is a Krishnamurthy number.\n", num);
    } else {
        printf("%d is not a Krishnamurthy number.\n", num);
    }

    return 0;
}
