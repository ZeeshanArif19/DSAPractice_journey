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
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        for(int i=0;i<queries.size();i++) queries[i].push_back(i);  //push original index so that can return answer in right order

        auto cmp=[&](vector<int> &a,vector<int> &b){
            return a[2]<b[2];
        };
        sort(edgeList.begin(),edgeList.end(),cmp);  //sort based on limit
        sort(queries.begin(),queries.end(),cmp);

        DSU ds(n);
        vector<bool> ans(queries.size());
        int edgeIdx=0;

        for(auto &it:queries){
            int u=it[0], v=it[1], limit=it[2], origIdx=it[3];
            //Add all edges that are strictly less than the current query's limit
            while(edgeIdx<edgeList.size() && edgeList[edgeIdx][2]<limit){
                ds.unite(edgeList[edgeIdx][0],edgeList[edgeIdx][1]);
                edgeIdx++;
            }
            
            ans[origIdx]=(ds.find(u)==ds.find(v));
        }
        return ans;
    }
};