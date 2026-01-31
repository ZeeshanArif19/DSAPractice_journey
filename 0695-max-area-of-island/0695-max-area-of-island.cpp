class Solution {
public:
    int dfs(vector<vector<int>>& grid,vector<vector<bool>>& vis,int r,int c,int n,int m){
        vis[r][c]=true;
        int area=1;
        vector<int> delRow={1,-1,0,0};
        vector<int> delCol={0,0,1,-1};
        for(int i=0;i<4;i++){
            int nr=r+delRow[i];
            int nc=c+delCol[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && grid[nr][nc]==1){
                area+=dfs(grid,vis,nr,nc,n,m);
            }
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        int maxarea=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    int area=dfs(grid,vis,i,j,n,m);
                    maxarea=max(area,maxarea);
                }
            }
        }
        return maxarea;
    }
};