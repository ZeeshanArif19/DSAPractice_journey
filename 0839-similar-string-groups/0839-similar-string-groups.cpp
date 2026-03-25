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
    bool isSimilar(string &s1,string &s2){
        int diff=0;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]) diff++;
            if(diff>2) return false;
        }
        return true;
    }
    int numSimilarGroups(vector<string>& strs) {
        int n=strs.size();
        int groups=n;
        DSU ds(n);
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(ds.find(i)!=ds.find(j)){
                    if(isSimilar(strs[i],strs[j])){
                        ds.unite(i,j);
                        groups--;
                    }
                }
            }
        }
        return groups;
    }
};