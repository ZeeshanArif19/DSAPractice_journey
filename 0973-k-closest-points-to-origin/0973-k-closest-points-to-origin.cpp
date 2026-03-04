class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n=points.size();
        vector<vector<int>> res;
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        //dist,x,y
        for(auto &it:points){
            int x=it[0];
            int y=it[1];
            int dist=(x*x)+(y*y);
            
            pq.push({dist,{x,y}});
        }
        while(k--){
            auto euc=pq.top();
            pq.pop();
            res.push_back({euc.second.first,euc.second.second});
        }
        return res;
    }
};