class Solution {
public:
    int solve(vector<vector<int>>& grid,vector<vector<vector<int>>> &dp,int row,int j1,int j2){ 
        int m=grid.size();
        int n=grid[0].size();

        if(j1>=n || j1<0 ||j2>=n || j2<0) return -1e9; //out of bounds reject the path
        if(dp[row][j1][j2]!=-1) return dp[row][j1][j2];

        int current_cherry= (j1==j2)? grid[row][j1] : grid[row][j1]+grid[row][j2];
        if(row==m-1) return current_cherry;

        int future_cherry=-1e9;
        for(int dj1=-1;dj1<=1;dj1++){
            for(int dj2=-1;dj2<=1;dj2++){
                future_cherry=max(future_cherry,solve(grid,dp,row+1,j1+dj1,j2+dj2));
            }
        }
        return dp[row][j1][j2]=current_cherry+future_cherry;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<vector<int>>> dp(m+1,vector<vector<int>>(n+1,vector<int>(n+1,-1))); //row,col1,col2
        return solve(grid,dp,0,0,n-1);
    }
};