class Solution {
public:
    bool isValid(vector<vector<int>>& manhatan,int n,int mid){
        int dr[4]={1,-1,0,0};
        int dc[4]={0,0,1,-1};
        if(manhatan[0][0]<mid) return false;
        //Is there a path from start to end where EVERY cell on the path is at least mid units away from any thief?
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        queue<pair<int,int>> q;
        q.push({0,0});
        vis[0][0]=true;

        while(!q.empty()){
            auto front=q.front();
            q.pop();
            int i=front.first;
            int j=front.second;
            if(i==n-1 && j==n-1) return true;

            for(int k=0;k<4;k++){
                int nr=i+dr[k];
                int nc=j+dc[k];
                if(nr>=0 && nr<n && nc>=0 && nc<n && !vis[nr][nc]){
                    if(manhatan[nr][nc]>=mid){
                        vis[nr][nc]=true;
                        q.push({nr,nc});
                    }
                }
            }
        }
        return false;
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> manhatan(n,vector<int>(n,INT_MAX));
        queue<pair<int,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    manhatan[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        int dr[4]={1,-1,0,0};
        int dc[4]={0,0,1,-1};

        while(!q.empty()){
            auto front=q.front();
            q.pop();
            int i=front.first;
            int j=front.second;

            for(int k=0;k<4;k++){
                int nr=i+dr[k];
                int nc=j+dc[k];
                if(nr>=0 && nr<n && nc>=0 && nc<n){
                    //Imagine dropping a pebble at every thief's location simultaneously
                    //Because all thieves start expanding at the exact same time, whichever thief's wave touches a cell first sets its minimum distance.
                    if(manhatan[nr][nc]==INT_MAX){
                        manhatan[nr][nc]=manhatan[i][j]+1;
                        q.push({nr,nc});
                    }
                }
            }
        }
        int l=0;
        int r=n*n;
        int ans=-1;

        while(l<=r){
            int mid=l+(r-l)/2;
            if(isValid(manhatan,n,mid)){
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        return ans;
    }
};