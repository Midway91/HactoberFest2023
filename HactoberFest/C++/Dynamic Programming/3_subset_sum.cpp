// Contributor: Shivani Swaraj
// User       : https://github.com/seventh-sense-claims


#include <bits/stdc++.h>
using namespace std;


// wt -> a, w -> sum
bool subset_sum(int a[], int n, int sum){

    bool dp[n+1][sum+1];

    for(int j=0; j<sum+1; j++)  dp[0][j] = false;
    for(int i=0; i<n+1; i++)    dp[i][0] = true;

    for(int i=1; i<n+1; i++)
        for(int j=1; j<sum+1; j++){
            if(a[i-1] <= j) dp[i][j] = dp[i-1][j-a[i-1]] || dp[i-1][j];
            else            dp[i][j] = dp[i-1][j];
        }

    // for(int i=0; i<n+1; i++){
    //     for(int j=0; j<sum+1; j++)
    //         printf("%d ", dp[i][j]);
    //     printf("\n");
    // }

    return dp[n][sum];
}


int main(){
    int a[] = {1, 2, 3, 5, 7, 8};
    int n = sizeof(a) / sizeof(int);
    int sum = 20;

    if(subset_sum(a, n, sum))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}