class Solution {
public:
    bool isValid(vector<vector<int>>& grid,vector<vector<int>>& fire_time,int mid,int m,int n){
        if(fire_time[0][0]<=mid) return false;

        vector<vector<bool>> vis(m,vector<bool>(n,false));
        queue<tuple<int,int,int>> q;
        q.push({mid,0,0});
        vis[0][0]=true;

        int dr[4]={1,-1,0,0};
        int dc[4]={0,0,1,-1};

        while(!q.empty()){
            auto[time,i,j]=q.front();
            q.pop();
            
            if(i==m-1 && j==n-1) return true;

            for(int k=0;k<4;k++){
                int nr=i+dr[k];
                int nc=j+dc[k];
                if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]!=2 && !vis[nr][nc]){
                    int new_time=time+1;
                    if(nr==m-1 && nc==n-1 && new_time<=fire_time[nr][nc]){
                        return true;
                    }
                    if(new_time<fire_time[nr][nc]){
                        q.push({new_time,nr,nc});
                        vis[nr][nc]=true;
                    }
                }
            }
        }
        return false;
    }
    int maximumMinutes(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        
        vector<vector<int>> fire_time(m,vector<int>(n,INT_MAX));
        queue<tuple<int,int,int>> q;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    fire_time[i][j]=0;
                    q.push({0,i,j});  //time,i,j
                }
            }
        }
        int dr[4]={1,-1,0,0};
        int dc[4]={0,0,1,-1};

        while(!q.empty()){
            auto[time,i,j]=q.front();
            q.pop();

            for(int k=0;k<4;k++){
                int nr=i+dr[k];
                int nc=j+dc[k];
                if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]==0){
                    int new_time=time+1;
                    if(new_time<fire_time[nr][nc]){
                        fire_time[nr][nc]=new_time;
                        q.push({new_time,nr,nc});
                    }
                }
            }
        }

        int l=0;
        int r=m*n;
        int ans=-1;

        while(l<=r){
            int mid=l+(r-l)/2;
            if(isValid(grid,fire_time,mid,m,n)){
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        
        if(ans==m*n) return 1e9;
        else return ans;
    }
};