#include <bits/stdc++.h>
using namespace std;

long long recursiveFibonacci(int n, vector<long long> &dp) {
    if (dp[n] == -1) {
        if (n <= 1) {
            dp[n] = n;
        } else {
            dp[n] = recursiveFibonacci(n - 1, dp) + recursiveFibonacci(n - 2, dp);
        }
    }
    return dp[n];
}

long long iterativeFibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    long long a = 0;
    long long b = 1;
    long long sum = 1;

    for (int i = 2; i <= n; i++) {
        sum = a + b;
        a = b;
        b = sum;
    }

    return sum;
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    vector<long long> dp(n + 1, -1);

    long long result = recursiveFibonacci(n, dp);
    cout << "The " << n << "th Fibonacci number (recursive) is: " << result << endl;

    result = iterativeFibonacci(n);
    cout << "The " << n << "th Fibonacci number (iterative) is: " << result << endl;

    return 0;
}

