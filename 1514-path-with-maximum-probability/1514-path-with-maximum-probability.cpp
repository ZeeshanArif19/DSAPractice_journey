class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>> adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            double prob=succProb[i];
            adj[u].push_back({v,prob});
            adj[v].push_back({u,prob});
        }

        priority_queue<pair<double,int>> pq; //prob,node
        vector<double> totprob(n,0);
        
        totprob[start_node]=1.0;
        pq.push({1.0,start_node});
        while(!pq.empty()){
            double pb=pq.top().first;
            int node=pq.top().second;
            pq.pop();

            if(node==end_node) return pb;
            if(pb<totprob[node]) continue;
            
            for(auto const &edge:adj[node]){
                int neighbour=edge.first;
                double probab=edge.second;
                if(totprob[node]*probab>totprob[neighbour]){
                    totprob[neighbour]=totprob[node]*probab;
                    pq.push({totprob[neighbour],neighbour});
                }
            }
        }
        return 0.00;
    }
};