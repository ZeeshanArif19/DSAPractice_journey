class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>> engineers;
        for(int i=0;i<n;i++){
            engineers.push_back({efficiency[i],speed[i]});
        }
        sort(engineers.begin(),engineers.end(),greater<pair<int,int>>());
        priority_queue<int,vector<int>,greater<int>> pq;
        
        long long maxPerf=0;
        long long speedSum=0;
        int MOD=1e9+7;

        for(auto &eng: engineers){
            int eff=eng.first;
            int spd=eng.second;
            
            speedSum+=spd;
            pq.push(spd);

            while(pq.size()>k){
                speedSum-=pq.top();
                pq.pop();
            }
            
            maxPerf=max(maxPerf,eff*speedSum);
        }
        return maxPerf%MOD;
    }
};