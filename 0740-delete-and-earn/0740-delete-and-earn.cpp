class Solution {
public:
    int solve(vector<int> &nums,int i,vector<int> &dp){
        if(i>=nums.size()) return 0;
        if(dp[i]!=-1) return dp[i];

        int currval=nums[i];
        int currsum=nums[i];
        int index=i+1;

        while(index<nums.size() && nums[index]==currval){
            currsum+=nums[index];
            index++;
        }
        while(index<nums.size() && nums[index]==currval+1){
            index++;
        }

        return dp[i]=max(currsum+solve(nums,index,dp),solve(nums,i+1,dp));
    }
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int> dp(n,-1);
        return solve(nums,0,dp);

    }
};