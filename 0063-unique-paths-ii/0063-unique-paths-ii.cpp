class Solution {
public:
    int solve(vector<vector<int>>& obstacleGrid,int i,int j,int m,int n,vector<vector<int>>& dp){
        if(i==m || j==n) return 0;
        if(obstacleGrid[i][j]==1) return 0;
        if(i==m-1 && j==n-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];

        if(i!=m && j!=n){
            dp[i][j]=solve(obstacleGrid,i+1,j,m,n,dp) + solve(obstacleGrid,i,j+1,m,n,dp);
        }
        return dp[i][j];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return solve(obstacleGrid,0,0,m,n,dp);
        
    }
};