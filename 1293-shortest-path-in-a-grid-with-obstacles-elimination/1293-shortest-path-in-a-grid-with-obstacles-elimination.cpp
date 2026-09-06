class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        if(m==1 && n==1) return 0;
        
        int dr[4]={1,-1,0,0};
        int dc[4]={0,0,1,-1};

        vector<vector<vector<int>>> dist(m,vector<vector<int>>(n,vector<int>(k+1,INT_MAX))); //r,c,elim
        using State=tuple<int,int,int,int>; //steps,r,c,elim
        priority_queue<State,vector<State>,greater<State>> pq;
        dist[0][0][0]=0;
        pq.push({0,0,0,0});

        while(!pq.empty()){
            auto [steps,r,c,elim]=pq.top();
            pq.pop();

            if(r==m-1 && c==n-1) return steps;
            if(steps>dist[r][c][elim]) continue;

            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 && nr<m && nc>=0 && nc<n){
                    int new_elim=elim+(grid[nr][nc]==1 ? 1:0);
                    int new_steps=steps+1;
                    
                    if(new_elim<=k && new_steps<dist[nr][nc][new_elim]){
                        dist[nr][nc][new_elim]=new_steps;
                        pq.push({new_steps,nr,nc,new_elim});
                    }
                }
            }
        }
        return -1;
    }
};