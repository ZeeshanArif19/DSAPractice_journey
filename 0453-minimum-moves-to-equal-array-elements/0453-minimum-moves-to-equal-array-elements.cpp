class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minval=*min_element(nums.begin(),nums.end());
        int totalmoves=0;
        for(int i=0;i<nums.size();i++){
            totalmoves+=nums[i]-minval;
        }
        return totalmoves;
    }
};