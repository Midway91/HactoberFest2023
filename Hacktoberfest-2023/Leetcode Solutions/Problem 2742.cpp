class Solution {
public:
    int f(int ind,int remain,vector<int>& cost,vector<int>& time,vector<vector<int>>& dp){
        if(ind==cost.size() && remain>0) return 1e9;
        if(remain<=0){
            return 0;
        }
        if(dp[ind][remain]!=-1) return dp[ind][remain];
        int take = cost[ind] + f(ind+1,remain-time[ind]-1,cost,time,dp);
        int nottake = f(ind+1,remain,cost,time,dp);

        return dp[ind][remain]=min(take,nottake);
    }


    int paintWalls(vector<int>& cost, vector<int>& time) {
       int n=cost.size();

       // Recusrion  + Memoization 
       //vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
       //return f(0,n,cost,time,dp);


        // Tabulation
        // vector<vector<int>> dp(n+1,vector<int> (n+1,0));
        // for(int i=1;i<=n;i++){
        //     dp[n][i] = 1e9;
        // }
        // for(int ind = n-1;ind>=0;ind--){
        //     for(int remain = 0;remain<=n;remain++){
        //         int take = cost[ind] + dp[ind+1][max(0,remain-time[ind]-1)]; 
        //         int nottake = dp[ind+1][max(0,remain)];

        //         dp[ind][max(0,remain)]=min(take,nottake);
        //     }
        // }
        // return dp[0][n];

        //Space optimized Tabulation
        vector<int> next(n+1,1e9);
        next[0] = 0;
        vector<int> curr(n+1,0);

        for(int ind = n-1;ind>=0;ind--){
            for(int remain = 0;remain<=n;remain++){
                int take = cost[ind] + next[max(0,remain-time[ind]-1)]; 
                int nottake = next[max(0,remain)];
                curr[max(0,remain)]=min(take,nottake);
            }
            next = curr;
        }
        
        return curr[n];





    }
};