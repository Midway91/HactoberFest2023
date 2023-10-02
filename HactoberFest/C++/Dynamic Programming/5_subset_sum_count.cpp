// Contributor: Shivani Swaraj
// User       : https://github.com/seventh-sense-claims


#include <bits/stdc++.h>


int subset_sum_count(int a[], int n, int sum){
    int dp[n+1][sum+1];

    for(int j=0; j<sum+1; j++)  dp[0][j] = 0;
    for(int i=0; i<n+1; i++)    dp[i][0] = 1;

    for(int i=1; i<n+1; i++)
        for(int j=1; j<sum+1; j++)
            if(a[i-1] <= j)     dp[i][j] = dp[i-1][j-a[i-1]] + dp[i-1][j];
            else                dp[i][j] = dp[i-1][j];

    return dp[n][sum];
}


int main(){
    int a[] = {1, 2, 3, 5, 7, 8};
    int n = sizeof(a) / sizeof(int);
    int sum = 10;

    printf("%d\n", subset_sum_count(a, n, sum));

    return 0;
}