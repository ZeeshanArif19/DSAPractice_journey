class Solution {
public:
    bool solve(vector<int> &nums,vector<int> &dp,int mask,int currentSum,int W,int k){
        if(k==1) return true;

        if(currentSum==W){
            return solve(nums,dp,mask,0,W,k-1);
        }
        if(dp[mask]!=-1) return dp[mask];
        
        for(int i=0;i<nums.size();i++){
            if((mask & (1<<i))!=0 && nums[i]+currentSum<=W){
                
                int nextmask=mask ^ (1<<i);
                
                if(solve(nums,dp,nextmask,currentSum+nums[i],W,k)){
                    return dp[mask]=1;
                }
            }
        }
        return dp[mask]=0;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%k!=0) return false;
        int W=sum/k;

        int initialMask=(1<<n+1)-1;
        vector<int> dp(initialMask+1,-1);

        return solve(nums,dp,initialMask,0,W,k);
    }
};