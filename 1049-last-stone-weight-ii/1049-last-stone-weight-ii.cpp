class Solution {
public:
    int solve(vector<int>& stones,vector<vector<int>> &dp,int &totsum,int n,int sum){
        if(n==0){
            return abs((2*sum)-totsum);
        }
        if(dp[n][sum]!=-1) return dp[n][sum];
        
        int pick=solve(stones,dp,totsum,n-1,sum+stones[n]);
        int notpick=solve(stones,dp,totsum,n-1,sum);

        return dp[n][sum]=min(pick,notpick);
    }
    int lastStoneWeightII(vector<int>& stones) {
        int n=stones.size();
        int totsum=0;
        for(int i:stones) totsum+=i;

        vector<vector<int>> dp(n+1,vector<int>(totsum+1,-1));
        return solve(stones,dp,totsum,n-1,0);
    }
};