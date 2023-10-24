#include <iostream>
#include <cmath>

using namespace std;

// Function to count the number of digits in a number
int countDigits(int number) {
    int count = 0;
    while (number != 0) {
        number /= 10;
        count++;
    }
    return count;
}

// Function to reverse a number
int reverseNumber(int number) {
    int reversed = 0;
    while (number != 0) {
        reversed = reversed * 10 + number % 10;
        number /= 10;
    }
    return reversed;
}

// Function to check if a number is a palindrome
bool isPalindrome(int number) {
    return number == reverseNumber(number);
}

// Function to check if a number is prime
bool isPrime(int number) {
    if (number <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(number); i++) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

// Function to print all divisors of a number
void printDivisors(int number) {
    cout << "Divisors of " << number << ": ";
    for (int i = 1; i <= number; i++) {
        if (number % i == 0) {
            cout << i << " ";
        }
    }
    cout << endl;
}

// Function to check if a number is an Armstrong number
bool isArmstrong(int number) {
    int originalNumber = number;
    int sum = 0;
    int n = countDigits(number);
    while (number != 0) {
        int digit = number % 10;
        sum += pow(digit, n);
        number /= 10;
    }
    return sum == originalNumber;
}

// Function to calculate the GCD (Greatest Common Divisor) of two numbers
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int choice, num;

    cout << "Math Operations Menu" << endl;
    cout << "1. Count Digits" << endl;
    cout << "2. Reverse a Number" << endl;
    cout << "3. Check Palindrome" << endl;
    cout << "4. Check Prime" << endl;
    cout << "5. Print All Divisors" << endl;
    cout << "6. Check Armstrong Number" << endl;
    cout << "7. Calculate GCD/HCF" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "Enter a number: ";
            cin >> num;
            cout << "Number of digits: " << countDigits(num) << endl;
            break;
        case 2:
            cout << "Enter a number: ";
            cin >> num;
            cout << "Reversed number: " << reverseNumber(num) << endl;
            break;
        case 3:
            cout << "Enter a number: ";
            cin >> num;
            if (isPalindrome(num)) {
                cout << "Palindrome" << endl;
            } else {
                cout << "Not a palindrome" << endl;
            }
            break;
        case 4:
            cout << "Enter a number: ";
            cin >> num;
            if (isPrime(num)) {
                cout << "Prime" << endl;
            } else {
                cout << "Not a prime" << endl;
            }
            break;
        case 5:
            cout << "Enter a number: ";
            cin >> num;
            printDivisors(num);
            break;
        case 6:
            cout << "Enter a number: ";
            cin >> num;
            if (isArmstrong(num)) {
                cout << "Armstrong number" << endl;
            } else {
                cout << "Not an Armstrong number" << endl;
            }
            break;
        case 7:
            int num1, num2;
            cout << "Enter the first number: ";
            cin >> num1;
            cout << "Enter the second number: ";
            cin >> num2;
            cout << "GCD/HCF: " << gcd(num1, num2) << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
    }

    return 0;
}
