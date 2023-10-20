# Interleaving String in Dp

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool solve(string & s1 , string &s2, string & s3,int ind1,int ind2, vector<vector<int>>&dp){
        if(ind1+ind2==s3.size()) return 1;
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        bool ans=0;
        if(ind1<s1.size()&& s1[ind1]==s3[ind1+ind2]){
            ans=(ans|solve(s1,s2,s3,ind1+1,ind2,dp));

        }
        if(ind2<s2.size()&& s2[ind2]==s3[ind1+ind2]){
            ans=(ans|solve(s1,s2,s3,ind1,ind2+1,dp));

        }
        return dp[ind1][ind2]=ans;
        
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size()) return false;
        vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1,-1));
        return solve(s1,s2,s3,0,0,dp);
    }
};
// Example 1

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true
Explanation: One way to obtain s3 is:
Split s1 into s1 = "aa" + "bc" + "c", and s2 into s2 = "dbbc" + "a".
Interleaving the two splits, we get "aa" + "dbbc" + "bc" + "a" + "c" = "aadbbcbcac".
Since s3 can be obtained by interleaving s1 and s2, we return true.
