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
    bool unite(int x,int y){
        int rootx=find(x);
        int rooty=find(y);
        if(rootx==rooty) return false;
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
        return true;
    }
};
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n=row.size();
        int totcouples=n/2;
        DSU ds(totcouples);

        int swaps=0;
        for(int i=0;i<n;i+=2){
            int first=row[i]/2;   //find the couple ID for both people on the couch
            int second=row[i+1]/2;
            if(ds.unite(first,second)){  //if the couple IDs are different we need to swap
                swaps++;
            }
        }
        return swaps;
    }
};