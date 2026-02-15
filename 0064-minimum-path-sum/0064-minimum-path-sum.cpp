class Solution {
public:
    int solve(vector<vector<int>>& grid,int i,int j,int m,int n,vector<vector<int>>& dp){
        if(i==m || j==n) return 1e9;
        if(i==m-1 && j==n-1) return grid[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(i!=m && j!=n){
            int min_cost=min(solve(grid,i+1,j,m,n,dp),solve(grid,i,j+1,m,n,dp));
            dp[i][j]=grid[i][j]+min_cost;
        }
        return dp[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m+1,vector<int> (n+1,-1));
        
        return solve(grid,0,0,m,n,dp);
    }
};