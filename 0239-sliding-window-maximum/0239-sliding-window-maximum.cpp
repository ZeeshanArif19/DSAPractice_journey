class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        int n=nums.size();
        deque<int> dq;
        int j=0;

        while(j<n){
            if(!dq.empty() && dq.front()<j-k+1){
                dq.pop_front();
            }
            while(!dq.empty() && nums[dq.back()]<nums[j]){
                dq.pop_back();
            }
            dq.push_back(j);
            
            if(j>=k-1){
                res.push_back(nums[dq.front()]);
            }
            j++;
        }
        return res;
    }
};