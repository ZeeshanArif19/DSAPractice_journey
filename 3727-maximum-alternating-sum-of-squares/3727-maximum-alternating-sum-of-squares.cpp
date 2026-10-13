class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        long long maxsum=0;

        for(int i=0;i<n;i++){ //square the array
            nums[i]*=nums[i];
        }
        sort(nums.begin(),nums.end());
        
        int i=0;
        int j=n-1;
        while(i<=j){
            if(i==j) {
                maxsum+=nums[i];
                break;
            }
            maxsum+=nums[j--];
            maxsum-=nums[i++];
        }
        return maxsum;
    }
};