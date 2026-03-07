class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq; //sum,i,j
        vector<vector<int>> res;

        int n1=nums1.size();
        int n2=nums2.size();

        for(int i=0;i<min(k,n1);i++){
            pq.push({nums1[i]+nums2[0],i,0});
        }
        while(k>0 && !pq.empty()){
            auto top=pq.top();
            pq.pop();
            int i=top[1];
            int j=top[2];

            res.push_back({nums1[i],nums2[j]});
            k--;

            if(j+1<n2){
                pq.push({nums1[i]+nums2[j+1],i,j+1});
            }
        }
        return res;
    }
};