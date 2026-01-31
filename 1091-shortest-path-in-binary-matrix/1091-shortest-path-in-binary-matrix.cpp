class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<vector<int>> q;

        if(grid[0][0]==1 || grid[n-1][m-1]==1) return -1;
        //row col distance
        q.push({0,0,1});
        grid[0][0]=1;
        vector<int> delRow={-1,-1,0,1,1,1,0,-1};
        vector<int> delCol={0,1,1,1,0,-1,-1,-1};

        while(!q.empty()){
            int r=q.front()[0];
            int c=q.front()[1];
            int dist=q.front()[2];
            q.pop();

            if(r==n-1 && c==m-1) return dist;

            for(int i=0;i<8;i++){
                int nr=r+delRow[i];
                int nc=c+delCol[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==0){
                    q.push({nr,nc,dist+1});
                    grid[nr][nc]=1;
                }
            }
        }
        return -1;
    }
};