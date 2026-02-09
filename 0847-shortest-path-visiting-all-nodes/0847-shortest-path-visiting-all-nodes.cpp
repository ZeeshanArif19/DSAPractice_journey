class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();
        if(n==1) return 0;

        vector<vector<bool>> vis(n,vector<bool>(1<<n,false));
        queue<vector<int>> q;
        
        for(int i=0;i<n;i++){
            int initial_mask=1<<i;
            q.push({i,initial_mask,0}); //node,mask,dist
            vis[i][initial_mask]=true;
        }

        int target_mask=(1<<n)-1;
        
        while(!q.empty()){
            vector<int> curr=q.front();
            q.pop();
            int node=curr[0];
            int mask=curr[1];
            int dist=curr[2];
            
            if(mask==target_mask) return dist;
        
            for(int neighbour: graph[node]){
                int newmask= mask | (1<<neighbour);

                if(!vis[neighbour][newmask]){
                    vis[neighbour][newmask]=true;
                    q.push({neighbour,newmask,dist+1});
                }
            }
        }
        return -1;
    }
};