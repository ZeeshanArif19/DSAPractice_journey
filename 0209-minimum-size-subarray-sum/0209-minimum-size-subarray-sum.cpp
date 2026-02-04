class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0,j=0;
        int minlen=INT_MAX;
        int sum=0;
        int n=nums.size();

        while(j<n){
            sum+=nums[j];
            while(sum>=target){
                sum-=nums[i];
                minlen=min(minlen,j-i+1);
                i++;
            }
            j++;
        }
        return minlen==INT_MAX? 0:minlen;
    }
};