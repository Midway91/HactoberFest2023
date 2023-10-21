?Number of distinct subsequences in Dp top questions of one


#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:	
	int distinctSubsequences(string s)
	{
	    // Your code goes here
	    int mod=1000000007;
	    int n=s.length();
	    vector<int>dp(n+1);
	    dp[0]=1;
	    unordered_map<char,int>mp;
	    for(int i=1;i<=n;i++){
	        char ch=s[i-1];
	        dp[i]=(2*dp[i-1])%mod;
	        if(mp.find(ch)!=mp.end()){
	            int index=mp[ch];
	            dp[i]=(dp[i]-dp[index-1]+mod)%mod;
	        }
	        mp[ch]=i;
	    }
	    return dp[n];
	}
};


//

Example 1:

Input: 
s = "gfg"
Output: 
7
Explanation: 
The seven distinct subsequences are "", "g", "f", "gf", "fg", "gg" and "gfg" .
