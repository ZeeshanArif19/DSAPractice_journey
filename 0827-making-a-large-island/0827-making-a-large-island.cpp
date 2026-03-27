class DSU{
    public:
    vector<int> parent;
    vector<int> size;
    DSU(int n){
        parent.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;i++) parent[i]=i;
    }
    int find(int x){
        if(x==parent[x]) return x;
        return parent[x]=find(parent[x]);
    }
    void uniteSize(int x,int y){
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
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        DSU ds(n*n);
        
        int dr[4]={1,-1,0,0};
        int dc[4]={0,0,1,-1};

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) continue;
                for(int k=0;k<4;k++){
                    int nr=i+dr[k];
                    int nc=j+dc[k];
                    if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==1){
                        int node=i*n+j;
                        int adjnode=nr*n+nc;
                        ds.uniteSize(node,adjnode);
                    }
                }
            }
        }
        
        int mx=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) continue;
                unordered_set<int> components;
                for(int k=0;k<4;k++){
                    int nr=i+dr[k];
                    int nc=j+dc[k];
                    if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==1){
                        components.insert(ds.find(nr*n+nc));
                    }
                }
                int sizeTot=0;
                for(auto &it:components){
                    sizeTot+=ds.size[it];
                }
                mx=max(mx,sizeTot+1);
            }
        }
        for(int i=0;i<n*n;i++){
            mx=max(mx,ds.size[ds.find(i)]);
        }
        return mx;
    }
};