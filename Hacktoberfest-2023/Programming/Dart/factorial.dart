// Define a function to calculate the factorial of a number.
int factorial(int n) {
  if (n <= 1) {
    return 1; // Base case: factorial of 0 and 1 is 1.
  } else {
    return n * factorial(n - 1); // Recursive case: n! = n * (n-1)!
  }
}

void main() {
  // Entry point of the program.
  int number = 5; // The number for which we want to calculate the factorial.
  int result = factorial(number); // Call the factorial function.
  
  // Print the result.
  print('Factorial of $number is $result');
}
