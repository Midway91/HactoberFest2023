// Link - https://leetcode.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps/description/?envType=daily-question&envId=2023-10-15
class Solution {
public:
    int numWays(int steps, int arrLen) {
        const int mod = 1000000007;
        
        int maxPosition = std::min(steps / 2, arrLen - 1);
    
        vector<vector<int>> dp(steps + 1, vector<int>(maxPosition + 1, 0));
        
        dp[0][0] = 1;
        
        for (int i = 1; i <= steps; i++) {
            for (int j = 0; j <= maxPosition; j++) {
               
                dp[i][j] = dp[i - 1][j];
                
             
                if (j > 0) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % mod;
                }
                
                if (j < maxPosition) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % mod;
                }
            }
        }
        return dp[steps][0];
    }
};
