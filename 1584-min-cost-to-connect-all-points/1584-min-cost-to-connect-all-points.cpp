class Solution {
public:
    int manhattanDist(vector<int> &p1,vector<int> &p2){
        return abs(p1[0]-p2[0]) + abs(p1[1]-p2[1]);
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<vector<pair<int,int>>> adj(n);  //u=>{v,weight}
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int w=manhattanDist(points[i],points[j]);
                
                adj[i].push_back({j,w});
                adj[j].push_back({i,w});
            }
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; //w,v
        vector<bool> vis(n,0);
        pq.push({0,0});
        int res=0;

        while(!pq.empty()){
            int wt=pq.top().first;
            int u=pq.top().second;
            pq.pop();
            
            if(vis[u]) continue;

            res+=wt;
            vis[u]=1;
            
            for(auto [nextNode,nextwt]: adj[u]){
                if(!vis[nextNode]){
                    pq.push({nextwt,nextNode});
                }
            }
        }
        return res;
    }
};