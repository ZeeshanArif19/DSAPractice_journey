class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n=nums.size();
        vector<pair<int,int>> val(n);
        for(int i=0;i<n;i++){
            val[i]={i,nums[i]};
        }
        sort(val.begin(),val.end(),[&](auto &a,auto &b){
            return a.second>b.second;
        });
        
        sort(val.begin(),val.begin()+k);

        vector<int> res(k);
        for(int i=0;i<k;i++){
            res[i]=val[i].second;
        }
        return res;
    }
};