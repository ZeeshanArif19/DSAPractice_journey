class DSU{
    public:
    unordered_map<int,int> parent;
    int findPar(int x){
        if(parent.find(x)==parent.end()){
            parent[x]=x;
        }
        if(x!=parent[x]){
            parent[x]=findPar(parent[x]);
        }
        return parent[x];
    }
    void unite(int x,int y){
        parent[findPar(x)]=findPar(y);
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DSU ds;
        for(auto &it:edges){
            int u=it[0];
            int v=it[1];
            if(ds.findPar(u)==ds.findPar(v)) return {u,v};
            else ds.unite(u,v);
        }
        return {};
    }
};