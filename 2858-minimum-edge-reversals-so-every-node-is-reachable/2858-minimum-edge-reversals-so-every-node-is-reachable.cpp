class Solution {
public:
    void dfsBase(unordered_map<int,vector<pair<int,int>>> &adj,int &baseRev,int parent,int prev){
        
        for(auto &child:adj[parent]){
            int childnode=child.first;
            int direction=child.second;
            if(childnode==prev) continue;
            baseRev+=direction;

            dfsBase(adj,baseRev,childnode,parent);
        }
    }
    void dfsreroot(unordered_map<int,vector<pair<int,int>>> &adj,vector<int> &res,int parent,int prev){
        
        for(auto &child:adj[parent]){
            int childnode=child.first;
            int direction=child.second;
            if(childnode==prev) continue;
            
            if(direction==1){
                res[childnode]=res[parent]-1;
            }
            else{
                res[childnode]=res[parent]+1;
            }
            dfsreroot(adj,res,childnode,parent);
        }
    }
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<pair<int,int>>> adj;
        vector<int> res(n,0);
        
        for(vector<int> &edge:edges){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back({v,0});
            adj[v].push_back({u,1});
        }

        int baseRev=0;
        dfsBase(adj,baseRev,0,-1);
        res[0]=baseRev;

        dfsreroot(adj,res,0,-1);

        return res;
    }
};