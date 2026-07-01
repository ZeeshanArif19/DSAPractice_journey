class Solution {
public:
    int solve(vector<vector<int>>& obstacleGrid,vector<vector<int>>& dp,int m,int n,int i,int j){
        if(i==m-1 && j==n-1) return 1;
        if(i==m || j==n) return 0;
        if(obstacleGrid[i][j]==1) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        if(i!=m && j!=n){
            dp[i][j]=solve(obstacleGrid,dp,m,n,i+1,j)+solve(obstacleGrid,dp,m,n,i,j+1);
        }
        return dp[i][j];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1]==1 || obstacleGrid[0][0]==1) return 0;

        vector<vector<long long>> dp(m+1,vector<long long>(n+1,0));
        // return solve(obstacleGrid,dp,m,n,0,0);

        dp[m-1][n-1]=1;
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==m-1 && j==n-1) continue;//to prevent overwriting of our base case
                if(obstacleGrid[i][j]==1){
                    dp[i][j]=0;
                    continue;
                }
                dp[i][j]=dp[i+1][j]+dp[i][j+1];
            }
        }

        return dp[0][0];
    }
};