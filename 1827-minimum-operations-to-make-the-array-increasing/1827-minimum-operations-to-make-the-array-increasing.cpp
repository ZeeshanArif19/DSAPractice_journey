class Solution {
public:
    int minOperations(vector<int>& nums) {
        int countOps=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>=nums[i+1]){
                int increment=nums[i]-nums[i+1]+1;
                countOps+=increment;
                nums[i+1]+=increment;
            }
        }
        return countOps;
    }
};