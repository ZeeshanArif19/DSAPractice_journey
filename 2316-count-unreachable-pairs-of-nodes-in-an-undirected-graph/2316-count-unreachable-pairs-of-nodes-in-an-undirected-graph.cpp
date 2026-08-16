class DSU{
    public:
    vector<int> parent;
    vector<int> rank;
    DSU(int n){
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++) parent[i]=i;
    }
    int find(int x){
        if(parent[x]==x) return parent[x];
        else return parent[x]=find(parent[x]);
    }
    void unite(int x,int y){
        int rootx=find(x);
        int rooty=find(y);
        if(rootx!=rooty){
            if(rank[rootx]<rank[rooty]){
                parent[rootx]=rooty;
            }
            else if(rank[rooty]<rank[rootx]){
                parent[rooty]=rootx;
            }
            else{
                parent[rooty]=rootx;
                rank[rootx]++;
            }
        }
    }
};
class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        DSU ds(n);
        
        for(int i=0;i<edges.size();i++){
            ds.unite(edges[i][0],edges[i][1]);
        }
        
        long long unreach=0;
        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++){
            int par=ds.find(i);
            mpp[par]++;
        }

        for(auto &it:mpp){
            int samePar=it.second;
            unreach+=(1LL*samePar*(n-samePar));
        }
        return unreach/2;
    }
};