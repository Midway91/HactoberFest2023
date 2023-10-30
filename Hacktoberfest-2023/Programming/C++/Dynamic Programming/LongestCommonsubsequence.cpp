//given two strings , find length of longest common subsequence

#include<bits/stdc++.h>
using namespace std;

int bu[100][100];//memorization

// recursion with memorixation (bootom up appraoch)
int lcs(string x,string y, int n, int m){ 
    if(n==0|| m==0) return 0; // if any string length is 0 than lcs is 0
    if(bu[m][n]!=-1) return bu[m][n];
    if(x[n-1]==y[m-1]) return  bu[m][n]=1+ lcs(x,y,n-1,m-1); // if last indexes matches than add 1 and go for remaining
    else {
        return  bu[m][n]=max(lcs(x,y,n,m-1),lcs(x,y,n-1,m)); // if last does not match leave the last of both 1 at a time and again find lcs
    }
}

int main(){
    string x;
    string y;
    cin>>x>>y;
    int n= x.length();
    int m=y.length();
    memset(bu,-1,sizeof(bu));
    cout<<lcs(x,y,n,m)<<endl;

    //Top-down

    int dp[n+1][m+1];

    //intialization
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            if(i==0 || j==0) dp[i][j]=0;
        }
    }

    //choice diagram
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(x[i-1]==y[j-1]) dp[i][j]=1+ dp[i-1][j-1];
            else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
        }
    }

    cout<<dp[n][m]<<endl;


    return 0;
}
