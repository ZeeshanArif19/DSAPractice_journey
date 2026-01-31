class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        int fresorang=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2) q.push({i,j});
                else if(grid[i][j]==1) fresorang++;
                else continue;
            }
        }
        if(fresorang==0) return 0;
        int min=0;
        
        int delrow[4]={1,-1,0,0};
        int delcol[4]={0,0,1,-1};
        while(!q.empty()){
            int size=q.size();
            bool rotted=false;

            while(size--){
                int r=q.front().first;
                int c=q.front().second;
                q.pop();
                
                for(int k=0;k<4;k++){
                    int nr=r+delrow[k];
                    int nc=c+delcol[k];

                    if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1){
                        grid[nr][nc]=2;
                        q.push({nr,nc});
                        fresorang--;
                        rotted=true;
                    }
                }
            }
            if(rotted==true) min++;
        }
        return fresorang==0?min:-1;
    }
};