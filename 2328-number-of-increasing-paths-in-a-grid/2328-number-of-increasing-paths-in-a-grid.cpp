class Solution {
public:
    int MOD=1e9+7;
    long long dfs(vector<vector<int>>& grid,vector<vector<long long>>& dp,int m,int n,int i,int j){
        
        if(dp[i][j]!=-1) return dp[i][j];

        static const int dr[4]={1,-1,0,0};
        static const int dc[4]={0,0,1,-1};
        long long count=0;

        for(int k=0;k<4;k++){
            int nr=i+dr[k];
            int nc=j+dc[k];
            if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]>grid[i][j]){
                count+=(1+dfs(grid,dp,m,n,nr,nc)); //count of increasing path from every cell
            }
        }
        return dp[i][j]=count%MOD;
    }
    int countPaths(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        long long count=0;
        vector<vector<long long>> dp(m+1,vector<long long>(n+1,-1));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                count+=dfs(grid,dp,m,n,i,j);
            }
        }
        count+=(m*n)%MOD;  //count of the individual elements in the cell
        return count%MOD;
    }
};