class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        
        queue<pair<int,int>> q;
        vector<vector<int>> dist(n,vector<int>(m,-1));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    dist[i][j]=0;
                }
            }
        }

        int delrow[4]={1,-1,0,0};
        int delcol[4]={0,0,1,-1};

        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            
            for(int k=0;k<4;k++){
                int nr=r+delrow[k];
                int nc=c+delcol[k];

                if(nr>=0 && nr<n && nc>=0 && nc<m && dist[nr][nc]==-1){
                    q.push({nr,nc});
                    dist[nr][nc]=dist[r][c]+1;
                }
            }
        }
        return dist;
    }
};