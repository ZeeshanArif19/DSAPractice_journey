class Solution {
public:
    int roblinear(vector<int> &nums,int i,int n,vector<int> &dp){
        if(i>n) return 0;
        if(dp[i]!=-1) return dp[i];
        
        int steal=nums[i]+roblinear(nums,i+2,n,dp);
        int skip=roblinear(nums,i+1,n,dp);
        return dp[i]=max(steal,skip);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        if(n==0) return 0;
        if(n==1) return nums[0];

        int op1=roblinear(nums,1,n-1,dp);
        fill(dp.begin(),dp.end(),-1);
        int op2=roblinear(nums,0,n-2,dp);

        return max(op1,op2);
    }
};