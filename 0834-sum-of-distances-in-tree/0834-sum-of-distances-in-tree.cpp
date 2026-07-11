class Solution {
public:
    int dfsbase(unordered_map<int,vector<int>> &adj,vector<int> &count,int curr_node,int prev_node,int curr_depth,int &root_res){
        int total_count=1;
        root_res+=curr_depth;
        
        for(int &child:adj[curr_node]){
            if(child==prev_node) continue;
            total_count+=dfsbase(adj,count,child,curr_node,curr_depth+1,root_res);
        }

        count[curr_node]=total_count;
        return total_count;
    }
    void dfs(unordered_map<int,vector<int>> &adj,vector<int> &res,vector<int> &count,int n,int parent_node,int prev_node){
        
        for(int &child:adj[parent_node]){
            if(child==prev_node) continue;

            res[child]=res[parent_node] - count[child] + (n-count[child]);
            dfs(adj,res,count,n,child,parent_node);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> adj;
        vector<int> count(n,0);
        vector<int> res(n,0);

        for(vector<int> &edge:edges){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int root_res=0;
        dfsbase(adj,count,0,-1,0,root_res);

        res[0]=root_res;
        dfs(adj,res,count,n,0,-1);

        return res;
    }
};