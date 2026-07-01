class Solution {
public:
    void dfs(int si,int sj,vector<vector<int>>& grid,int &m,int &n,int &steps,int &waysCnt,int &zeroCnt){
        int dr[4]={1,-1,0,0};
        int dc[4]={0,0,1,-1};
        
        if(grid[si][sj]==2 && steps==zeroCnt){ //I've reached the destination, and I've already visited every empty cell exactly once.
            waysCnt++;
            return;
        }
        int temp=grid[si][sj];  //store the original val to restore the grid to original state when backtracking
        grid[si][sj]=-1;
    
        for(int k=0;k<4;k++){
            int nr=si+dr[k];
            int nc=sj+dc[k];
            if(nr>=0 && nr<m && nc>=0 && nc<n){  //we are allowed to move if the grid val is 0 or 2
                if(grid[nr][nc]==0){ //if 0 also count steps
                    steps++;  //no of empty cells visited so far
                    dfs(nr,nc,grid,m,n,steps,waysCnt,zeroCnt);
                    steps--;
                }
                else if(grid[nr][nc]==2){ //if 2 just recurse
                    dfs(nr,nc,grid,m,n,steps,waysCnt,zeroCnt);
                }
            }
        }
        grid[si][sj]=temp; //backtrack to original val
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int waysCnt=0;
        int m=grid.size();
        int n=grid[0].size();
        
        int si,sj;
        int zeroCnt=0;
        int steps=0;
        for(int i=0;i<m;i++){  //find the starting coords
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    si=i;
                    sj=j;
                }
                else if(grid[i][j]==0) zeroCnt++; //also count empty squares
            }
        }
        
        dfs(si,sj,grid,m,n,steps,waysCnt,zeroCnt);
        
        return waysCnt;
    }
};