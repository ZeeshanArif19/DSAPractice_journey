class Solution {
public:
    void dfs(vector<vector<int>>& grid,vector<vector<bool>> &vis,int n,int m,int r,int c){
        vis[r][c]=true;
        grid[r][c]=0;
        vector<int> delRow={1,-1,0,0};
        vector<int> delCol={0,0,1,-1};
        for(int i=0;i<4;i++){
            int nr=r+delRow[i];
            int nc=c+delCol[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && grid[nr][nc]==1){
                grid[nr][nc]=0;
                dfs(grid,vis,n,m,nr,nc);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        //check graph
        for(int j=0;j<m;j++){
            if(grid[0][j]==1) dfs(grid,vis,n,m,0,j);
            if(grid[n-1][j]==1) dfs(grid,vis,n,m,n-1,j);
        }
        for(int i=0;i<n;i++){
            if(grid[i][0]==1) dfs(grid,vis,n,m,i,0);
            if(grid[i][m-1]==1) dfs(grid,vis,n,m,i,m-1);
        }

        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) count++;
            }
        }
        return count;
    }
};