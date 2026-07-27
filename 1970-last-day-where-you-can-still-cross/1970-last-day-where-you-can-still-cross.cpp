class Solution {
public:
    bool isValid(vector<vector<int>>& water_time,int row,int col,int mid){
        vector<vector<bool>> vis(row,vector<bool>(col,false));
        int dr[4]={1,-1,0,0};
        int dc[4]={0,0,1,-1};
        
        queue<pair<int,int>> q;
        for(int j=0;j<col;j++){
            if(water_time[0][j]>mid){
                q.push({0,j});
                vis[0][j]=true;
            }
        }

        while(!q.empty()){
            auto front=q.front();
            q.pop();
            int i=front.first;
            int j=front.second;
            
            if(i==row-1) return true;

            for(int k=0;k<4;k++){
                int nr=i+dr[k];
                int nc=j+dc[k];
                if(nr>=0 && nr<row && nc>=0 && nc<col){
                    if(water_time[nr][nc]>mid && !vis[nr][nc]){
                        q.push({nr,nc});
                        vis[nr][nc]=true;
                    }
                }
            }
        }
        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {

        vector<vector<int>> water_time(row,vector<int>(col,0));
        int time=1;

        for(int i=0;i<cells.size();i++){
            int u=cells[i][0]-1;
            int v=cells[i][1]-1;
            water_time[u][v]=time;
            time++;
        }

        int l=0;
        int r=row*col;
        int ans=-1;

        while(l<=r){
            int mid=l+(r-l)/2;
            if(isValid(water_time,row,col,mid)){
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        return ans;
    }
};