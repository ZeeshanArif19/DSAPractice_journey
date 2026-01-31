class Solution {
public:
    void bfs(int node,unordered_map<int,bool> &visited,vector<vector<int>> &isConnected){
        queue<int> q;
        q.push(node);
        visited[node]=true;
        while(!q.empty()){
            int front=q.front();
            q.pop();
            for(int j=0;j<isConnected.size();j++){
                if(isConnected[front][j]==1 && !visited[j]){
                    visited[j]=true;
                    q.push(j);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int count=0;
        unordered_map<int,bool> visited;
        
        for(int i=0;i<n;i++){
            if(!visited[i]){
                count++;
                bfs(i,visited,isConnected);
            }
        }
        return count;
    }
};