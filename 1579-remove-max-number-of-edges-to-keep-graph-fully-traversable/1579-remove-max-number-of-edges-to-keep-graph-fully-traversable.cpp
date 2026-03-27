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
        if(rootx==rooty) return;
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
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        sort(edges.begin(),edges.end(),greater<vector<int>>());

        DSU ds1(n);
        DSU ds2(n);
        int removedEdges=0;
        int aliceUnion=0;
        int bobUnion=0;
        for(auto &it:edges){
            int type=it[0];
            int u=it[1];
            int v=it[2];

            if(type==3){
                if(ds1.find(u)==ds1.find(v)) removedEdges++;
                else{
                    ds1.unite(u,v);
                    ds2.unite(u,v);
                    aliceUnion++;
                    bobUnion++;
                }
            }
            else if(type==1){
                if(ds1.find(u)==ds1.find(v)) removedEdges++;
                else{
                    ds1.unite(u,v);
                    aliceUnion++;
                }
            }
            else{
                if(ds2.find(u)==ds2.find(v)) removedEdges++;
                else{
                    ds2.unite(u,v);
                    bobUnion++;
                }
            }
        }

        if(aliceUnion!=n-1 || bobUnion!=n-1) return -1;
        return removedEdges;
    }
};