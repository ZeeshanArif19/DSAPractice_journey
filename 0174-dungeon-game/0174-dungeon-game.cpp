class Solution {
public:
    int solve(vector<vector<int>>& dungeon,int i,int j,int m,int n,vector<vector<int>>& dp){
        if(i==m || j==n) return 1e9;
        if(i==m-1 && j==n-1) return max(1,1-dungeon[i][j]);
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(i!=m && j!=n){
            dp[i][j]=max(1,min(solve(dungeon,i+1,j,m,n,dp),solve(dungeon,i,j+1,m,n,dp))-dungeon[i][j]);
        }
        return dp[i][j];
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m=dungeon.size();
        int n=dungeon[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,1e9));
        // return solve(dungeon,0,0,m,n,dp);

        dp[m-1][n-1]=max(1,1-dungeon[m-1][n-1]);

        // for(int i=0;i<m;i++) dp[i][n]=1e9;
        // for(int j=0;j<n;j++) dp[m][j]=1e9;

        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==m-1 && j==n-1) continue;
                dp[i][j]=max(1,min(dp[i+1][j],dp[i][j+1])-dungeon[i][j]);

            }
        }
        return dp[0][0];
    }
};