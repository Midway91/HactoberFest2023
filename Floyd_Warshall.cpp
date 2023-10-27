class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
//         n^3
        vector<vector<long long int>> dp(n,vector<long long int>(n,INT_MAX));
        
        for(int i=0;i<n;i++){
            dp[i][i]=0;
        }
        for(int i=0;i<edges.size();i++){
            dp[edges[i][0]][edges[i][1]]=edges[i][2];
            dp[edges[i][1]][edges[i][0]]=edges[i][2];
        }
        
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(i!=j){
                       if(dp[i][k]!=INT_MAX && dp[k][j]!=INT_MAX){
                          dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
                       }
                    }
                }
            }
        }
        vector<pair<int,int>> ans;
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(dp[i][j]<=distanceThreshold){
                    count++;
                }
            }
            ans.push_back({count,-i});
        }
        sort(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++){
            cout<<ans[i].first<<" "<<ans[i].second<<endl;
        }
        // int get=ans.begin().second
        return -ans[0].second;
    }
};
