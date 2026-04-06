class DSU{
    public:
    vector<int> parent;
    vector<int> size;
    DSU(int n){
        parent.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int find(int x){
        if(x==parent[x]) return x;
        return parent[x]=find(parent[x]);
    }
    void unite(int x,int y){
        int rootx=find(x);
        int rooty=find(y);
        if(rootx!=rooty){
            if(size[rootx]<size[rooty]){
                parent[rootx]=rooty;
                size[rooty]+=size[rootx];
            }
            else{
                parent[rooty]=rootx;
                size[rootx]+=size[rooty];
            }
        }
    }
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        DSU ds(n);
        int components=n;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && ds.find(i)!=ds.find(j)){
                    ds.unite(i,j);
                    components--;
                }
            }
        }
        return components;
    }
};