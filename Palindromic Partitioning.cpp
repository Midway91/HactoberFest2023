#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
        bool isPalindrome(int i,int j,string &s){
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    int palindromicPartition(string str)
    {
        vector<int>dp(str.size()+1,0);
        for(int i=str.size()-1;i>=0;i--){
            int mincost=INT_MAX;
            for(int j=i;j<str.size();j++){
                if(isPalindrome(i,j,str)){
                int cost=1+dp[j+1];
                mincost=min(mincost,cost);
            }
            }
            dp[i]=mincost;
        }
        return dp[0]-1;
    }
};


int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
