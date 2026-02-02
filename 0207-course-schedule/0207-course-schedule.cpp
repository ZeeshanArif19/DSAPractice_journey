class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,list<int>> adj;
        for(int i=0;i<prerequisites.size();i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            adj[u].push_back(v);
        }
        //calc indegree
        vector<int> indegree(numCourses,0);
        for(int i=0;i<numCourses;i++){
            for(auto neighbour:adj[i]){
                indegree[neighbour]++;
            }
        }
        //push staters
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0)
                q.push(i);
        }
        //bfs
        vector<int> topo;
        while(!q.empty()){
            int front=q.front();
            q.pop();
            topo.push_back(front);

            for(auto i:adj[front]){
                indegree[i]--;
                if(indegree[i]==0){
                    q.push(i);
                }
            }
        }
        //cycle detection
        if(topo.size()<numCourses) return false;  //because nodes in a cycle nver reach indegree 0
        return true;
    }
};