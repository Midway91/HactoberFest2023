You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.


  // RECURSION
  class Solution {
public:
    
    int f(int ind,vector<int>& nums)
    {
        if(ind==0)
        {
            return nums[ind];
        }
        if(ind<0)
            return 0;
        int nottake=f(ind-1,nums);
     //   int take=INT_MIN;
    //    if(ind>1)
           int take=nums[ind]+f(ind-2,nums);
        return max(take,nottake);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        return f(n-1,nums);
    }
};


// MEMOIZATION
class Solution {
public:
    
    int f(int ind,vector<int>& nums, vector<int>&dp)
    {
        if(ind==0)
        {
            return nums[ind];
        }
        if(ind<0)
            return 0;
        if(dp[ind]!=-1)
            return dp[ind];
        int nottake=f(ind-1,nums,dp);
     //  int take=INT_MIN;
     //  if(ind>1)
           int take=nums[ind]+f(ind-2,nums,dp);
        return dp[ind]=max(take,nottake);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return f(n-1,nums,dp);
    }
};

// TABULATION
class Solution {
public:
    
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,0);
        dp[0]=nums[0];
        for(int i=1;i<n;i++)
        {
           
        int nottake=dp[i-1];
        int take=nums[i];
        if(i>1)
        take+=dp[i-2];
        dp[i]=max(take,nottake);

        }
        return dp[n-1];
    }
};

