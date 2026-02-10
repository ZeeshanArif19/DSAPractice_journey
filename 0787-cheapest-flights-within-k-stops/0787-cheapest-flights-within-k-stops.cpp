class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,list<pair<int,int>>> adj;
        for(int i=0;i<flights.size();i++){
            int u=flights[i][0];
            int v=flights[i][1];
            int w=flights[i][2];
            adj[u].push_back({v,w});
        }
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<int> min_stops(n,INT_MAX);
        pq.push({0,src,0});  //cost node stops

        while(!pq.empty()){
            int node=pq.top()[1];
            int cost=pq.top()[0];
            int stops_sofar=pq.top()[2];
            pq.pop();

            if(node==dst) return cost;
            if(stops_sofar>k) continue;
            if(min_stops[node]<=stops_sofar) continue;
            min_stops[node]=stops_sofar;

            for(auto &it:adj[node]){
                int newNode=it.first;
                int w=it.second;
                pq.push({cost+w,newNode,stops_sofar+1});
            }
        }
        return -1;
    }
};