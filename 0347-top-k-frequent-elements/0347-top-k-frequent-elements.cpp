class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;  //freq,element
        unordered_map<int,int> mpp; //element,freq
        vector<int> res;

        for(int &i:nums){
            mpp[i]++;
        }
        for(auto &it:mpp){
            pq.push({it.second,it.first});
        }
        
        for(int i=0;i<k;i++){
            int el=pq.top().second;
            res.push_back(el);
            pq.pop();
        }
        return res;
    }
};