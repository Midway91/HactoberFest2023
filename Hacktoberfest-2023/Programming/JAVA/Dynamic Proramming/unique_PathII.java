class Solution {
    int n1, m1;
    public int solve(int i, int j, int[][] dp, int[][] obstacleGrid){
        if(i==m1-1 && j==n1-1) return 1;
        if(i==m1 || j==n1) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        if(obstacleGrid[i][j]==1) return 0;
        return dp[i][j]=solve(i+1, j, dp, obstacleGrid)+solve(i, j+1, dp, obstacleGrid);
    }
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        m1=obstacleGrid.length;n1=obstacleGrid[0].length;
        if(obstacleGrid[0][0]==1 || obstacleGrid[m1-1][n1-1]==1) return 0;
       int[][] dp = new int[m1][n1];

        for(int i=0; i<m1; i++){
            Arrays.fill(dp[i], -1);
        }
        return solve(0, 0, dp,obstacleGrid);
    }
}