class Solution {
public:
    void dfs(vector<vector<int>>& grid,vector<vector<bool>>& vis,int m,int n,int row,int col,int &perimeter){
        vis[row][col]=true;
        
        int dr[4]={1,-1,0,0};
        int dc[4]={0,0,1,-1};
        
        for(int k=0;k<4;k++){
            int nr=row+dr[k];
            int nc=col+dc[k];
            if(nr<0 || nr>=m || nc<0 || nc>=n || grid[nr][nc]==0){
                perimeter++;
            }
            else if(grid[nr][nc]==1 && !vis[nr][nc]){
                dfs(grid,vis,m,n,nr,nc,perimeter);
            }
        }
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        int perimeter=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    dfs(grid,vis,m,n,i,j,perimeter);
                }
            }
        }
        return perimeter;
    }
};