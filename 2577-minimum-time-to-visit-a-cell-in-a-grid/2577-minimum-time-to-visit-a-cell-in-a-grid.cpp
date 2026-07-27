class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        if(grid[0][1]>1 && grid[1][0]>1) return -1;

        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;  //minheap time,i,j

        vector<vector<int>> dist(m,vector<int>(n,INT_MAX));
        dist[0][0]=0;
        pq.push({0,{0,0}});
        
        int dr[4]={1,-1,0,0};
        int dc[4]={0,0,1,-1};

        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();
            int time=top.first;
            int i=top.second.first;
            int j=top.second.second;

            if(i==m-1 && j==n-1) return time;
            if(time>dist[i][j]) continue;

            for(int k=0;k<4;k++){
                int nr=i+dr[k];
                int nc=j+dc[k];
                if(nr>=0 && nr<m && nc>=0 && nc<n){
                    int new_time=0;
                    if(time>=grid[nr][nc]){
                        new_time=time+1;
                    }
                    else if(time<grid[nr][nc]){
                        int waiting_time=grid[nr][nc]-time;

                        if(waiting_time%2==1) new_time=grid[nr][nc];
                        else new_time=grid[nr][nc]+1;
                    }

                    if(new_time<dist[nr][nc]){
                        dist[nr][nc]=new_time;
                        pq.push({new_time,{nr,nc}});
                    }
                }
            }
        }
        return -1;
    }
};