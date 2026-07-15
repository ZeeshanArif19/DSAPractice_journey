class Solution {
public:
    void dfs(vector<vector<pair<int,int>>> &adj,int curr_node,int prev_node,int &changes){
    
        for(auto &it:adj[curr_node]){
            int edge=it.first;
            int direction=it.second;
            if(edge==prev_node) continue;
            changes+=direction;
            dfs(adj,edge,curr_node,changes);
        }
        
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<n-1;i++){
            int u=connections[i][0];
            int v=connections[i][1];
            adj[u].push_back({v,1});
            adj[v].push_back({u,0});
        }

        int changes=0;
        dfs(adj,0,-1,changes);
        return changes;
    }
};