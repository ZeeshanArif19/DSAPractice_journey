class Solution {
public:
    int solve(vector<int>& nums,int i,int &W,int sum,vector<vector<int>> &dp){
        if(i==nums.size() && sum==W) return 1;
        if(i==nums.size() && sum!=W) return 0;
        if(dp[i][sum]!=-1) return dp[i][sum];

        int pick=0;
        if(sum+nums[i]<=W){
            pick=solve(nums,i+1,W,sum+nums[i],dp);
        }
        int notpick=solve(nums,i+1,W,sum,dp);
        return dp[i][sum]=pick+notpick;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int totsum=0;
        for(int i=0;i<n;i++) totsum+=nums[i];

        if(abs(target)>totsum || totsum+target<0 || (target+totsum)%2==1) return 0;
        int W=(totsum+target)/2;

        vector<vector<int>> dp(n+1,vector<int>(W+1,-1));
        return solve(nums,0,W,0,dp);
    }
};