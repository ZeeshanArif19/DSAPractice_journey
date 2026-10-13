class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        long long maxsum=0;
        int h=n/2;

        for(int i=0;i<n;i++){ //square the array
            nums[i]*=nums[i];
        }
        nth_element(nums.begin(),nums.begin()+h,nums.end());
        
        for(int i=0;i<n;i++){
            maxsum+=(i<h?-1:1) * nums[i];
        }
        return maxsum;
    }
};