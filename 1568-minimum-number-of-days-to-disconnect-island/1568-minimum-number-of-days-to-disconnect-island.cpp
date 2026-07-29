class Solution {
public:
    void tarjan(int node,int parent,vector<vector<int>> &adj,vector<bool> &vis,vector<int> &tin,vector<int> &low,vector<bool> &mark,int &timer){
        
        vis[node]=1;
        tin[node]=low[node]=timer;
        timer++;
        int child=0;

        for(auto &it:adj[node]){
            if(it==parent) continue;
            if(!vis[it]){
                tarjan(it,node,adj,vis,tin,low,mark,timer);
                low[node]=min(low[node],low[it]);

                if(low[it]>=tin[node] && parent!=-1){
                    mark[node]=1;
                }
                child++;
            }
            else{
                low[node]=min(low[node],tin[it]); //for undirected
            }
        }
        if(child>1 && parent==-1) mark[node]=1;
    }
    int minDays(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> adj(n*m);
        
        int dr[4]={1,-1,0,0};
        int dc[4]={0,0,1,-1};
        int totalands=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    totalands++;
                    int u=i*n+j;
                    
                    for(int k=0;k<4;k++){
                        int nr=i+dr[k];
                        int nc=j+dc[k];
                        if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]==1){
                            int v=nr*n+nc;
                            adj[u].push_back(v);
                        }
                    }
                }
            }
        }

        vector<bool> vis(m*n,false);
        vector<bool> mark(m*n,false);
        vector<int> tin(m*n,0);
        vector<int> low(m*n,0);
        int timer=1;
        int islands=0;

        for(int i=0;i<m*n;i++){
            int r=i/n;
            int c=i%n;

            if(grid[r][c]==1 && !vis[i]){
                islands++;
                if(islands>1) return 0; //already disconnected
                tarjan(i,-1,adj,vis,tin,low,mark,timer);
            }
        }

        if(islands==0) return 0;
        if(totalands==1) return 1;

        for(int i=0;i<m*n;i++){
            if(mark[i]==1) return 1;  //articulation point exists
        }

        return 2; //islands is 1 but no articulation point it is gauranteed that 2 removals will make is disconnected
    }
};