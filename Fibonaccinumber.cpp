#include <bits/stdc++.h>
using namespace std;

/*finding nth fibonacci number using dynamic programming */

long int fibonacci(int n, vector<int> &dp)
{
    if (dp[n] == -1)
    {
        if (n <= 1)
            dp[n] = n;
        else
            return dp[n] = fibonacci(n - 1,dp) + fibonacci(n - 2,dp);
    }
    return dp[n];
}

/*Iterative procedure for finding nth fibonacci number

long int fibonacci(int n) {

     long int a = 0;
    long int b = 1;
    long int sum=1;

    if (n <=1) {
        return n;
    }
    for (int i = 2; i <= n; i++) {
        sum = a + b;
        a = b;
        b = sum;
    }

    return sum;
}
*/

int main()
{
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    vector<int> dp(n + 1, -1);

    long int sum = fibonacci(n, dp);

    cout << "The " << n << "th Fibonacci number is: " << sum << endl;

    return 0;
}
