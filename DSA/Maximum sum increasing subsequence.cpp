# GFG Problem
# Link: https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1
# Refer driver code from above gfg link

# Main code

class Solution{
	public:
	int maxSumIS(int a[], int n){ 
        vector<int> dp(a,a+n);
	    int ans=dp[0];
	    for(int i=1;i<n;i++){
	        for(int j=i-1;j>=0;j--){
	            if(a[j]<a[i]){
	                dp[i] = max(dp[i],dp[j]+a[i]);
	            }
	        }
	        ans = max(ans,dp[i]);
	    }
	    return ans;
	}
};
