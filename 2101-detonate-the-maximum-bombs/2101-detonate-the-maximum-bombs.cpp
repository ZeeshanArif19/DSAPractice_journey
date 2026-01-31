class Solution {
public:
    int dfs(unordered_map<int,list<int>> &adj,vector<bool> &vis,int src){
        vis[src]=true;
        int count=1;
        for(int i:adj[src]){
            if(!vis[i]){
                count+=dfs(adj,vis,i);
            }
        }
        return count;
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        //build graph
        int n=bombs.size();
        unordered_map<int,list<int>> adj;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) continue;
                
                long long x1=bombs[i][0];
                long long y1=bombs[i][1];
                long long radius=bombs[i][2];

                long long x2=bombs[j][0];
                long long y2=bombs[j][1];
                //calculate euclidean distance between i and j bombs
                long long dx=x1-x2;
                long long dy=y1-y2;
                long long dist=(dx*dx)+(dy*dy);

                if(dist<=(radius*radius)){
                    adj[i].push_back(j);
                }
            }
        }

        int maxCount=0;
        for(int i=0;i<n;i++){
            vector<bool> vis(n,false);
            int count=dfs(adj,vis,i);
            maxCount=max(maxCount,count);
        }
        return maxCount;
    }
};