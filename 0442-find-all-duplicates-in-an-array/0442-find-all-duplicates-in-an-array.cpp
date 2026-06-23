class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        
        for(int i=0;i<nums.size();i++){
            int flipInd=abs(nums[i])-1;
            if(nums[flipInd]<0) res.emplace_back(flipInd+1);
            else nums[flipInd]=-nums[flipInd];
        }

        return res;
    }
};