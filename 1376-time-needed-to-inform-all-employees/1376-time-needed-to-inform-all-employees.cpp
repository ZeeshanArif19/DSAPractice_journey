class Solution {
public:
    void dfs(vector<vector<int>> &adj,vector<int>& informTime,int src,int &maxTime,int pathTime){
        pathTime+=informTime[src];
        maxTime=max(maxTime,pathTime);

        for(int &neighbour:adj[src]){
            dfs(adj,informTime,neighbour,maxTime,pathTime);
        }
    } //the time to inform all employees must the max time down a path
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            if(manager[i]!=-1)
                adj[manager[i]].push_back(i);
        }
    
        int maxTime=0;
        dfs(adj,informTime,headID,maxTime,0);

        return maxTime;
    }
};