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
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n=s.size();
        DSU ds(n);
        for(auto &edge:pairs){  // Connect all indices that are allowed to be swapped
            ds.unite(edge[0],edge[1]);
        }

        unordered_map<int,vector<char>> groups;
        for(int i=0;i<n;i++){   // Group characters by their absolute root after all unions
            int root=ds.find(i);
            groups[root].push_back(s[i]);
        }
        
        for(auto &it:groups){  // Sort in descending order to use pop_back() efficiently
            sort(it.second.begin(),it.second.end(),greater<char>());
        }

        string res="";
        for(int i=0;i<n;i++){
            int root=ds.find(i);
            res+=groups[root].back();
            groups[root].pop_back();
        }
        return res;
    }
};