class Solution {
public:
    void dfs(int node,int parent,vector<vector<int>> &adj,vector<bool> &vis,vector<int> &tin,vector<int> &low,int &timer,vector<vector<int>> &bridges){
        
        vis[node]=1;
        tin[node]=low[node]=timer;
        timer++;
        
        for(auto &it:adj[node]){
            if(it==parent) continue;
            if(!vis[it]){
                dfs(it,node,adj,vis,tin,low,timer,bridges);
                low[node]=min(low[node],low[it]);

                if(low[it]>tin[node]){
                    bridges.push_back({node,it});
                }
            }
            else{
                low[node]=min(low[node],low[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto &edge:connections){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> vis(n,0);
        vector<int> tin(n);
        vector<int> low(n);
        int timer=1;
        vector<vector<int>> bridges;

        dfs(0,-1,adj,vis,tin,low,timer,bridges);

        return bridges;
    }
};