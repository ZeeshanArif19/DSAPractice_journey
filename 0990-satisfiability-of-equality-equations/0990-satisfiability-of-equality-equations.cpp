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
        if(x==parent[x]) return x;
        return parent[x]=find(parent[x]);
    }
    void unite(int x,int y){
        int rootx=find(x);
        int rooty=find(y);
        if(rank[rootx]<rank[rooty]){
            parent[rootx]=rooty;
        }
        else if(rank[rootx]>rank[rooty]){
            parent[rooty]=rootx;
        }
        else{
            parent[rootx]=rooty;
            rank[rooty]++;
        }
    }
};
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        DSU ds(26);
        for(int i=0;i<equations.size();i++){
            int u=equations[i][0]-'a';
            int v=equations[i][3]-'a';
            if(equations[i][1]=='='){
                ds.unite(u,v);
            }
        }

        for(int i=0;i<equations.size();i++){
            int u=equations[i][0]-'a';
            int v=equations[i][3]-'a';
            if(equations[i][1]=='!'){
                if(ds.find(u)==ds.find(v)) return false;
            }
        }
        return true;
    }
};