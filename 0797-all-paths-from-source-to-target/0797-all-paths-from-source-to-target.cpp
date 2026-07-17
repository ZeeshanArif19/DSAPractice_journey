class Solution {
public:
    void dfs(vector<vector<int>>& adj,int src,vector<vector<int>> &res,vector<int> &path,int n){
        path.push_back(src);

        for(int &neighbour:adj[src]){
            dfs(adj,neighbour,res,path,n);
        }
        if(src==n-1){
            res.push_back(path);
        }
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>> res;
        vector<int> path;
        
        dfs(graph,0,res,path,n);
        return res;
    }
};