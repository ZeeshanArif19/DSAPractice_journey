class DSU{
    public:
    vector<int> parent;
    vector<int> rank;
    DSU(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        for(int i=0;i<=n;i++) parent[i]=i;
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
    int gcd(int x,int y){
        if(y==0) return x;
        return gcd(y,x%y);
    }
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        DSU ds(n);
        vector<bool> res(queries.size());
        
        for(int i=threshold+1;i<=n;i++){ //Loop through every valid divisor starting just above the threshold and connect them
            for(int j=i*2;j<=n;j+=i){
                ds.unite(i,j);
            }
        }
        int idx=0;
        for(auto &it:queries){
            int u=it[0];
            int v=it[1];
            res[idx]=(ds.find(u)==ds.find(v));
            idx++;
        }
        return res;
    }
};