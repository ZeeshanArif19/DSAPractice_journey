class Solution {
public:
    int solve(vector<int>& coins,int n,int amount,vector<vector<int>> &dp){
        if(n==0){
            if(amount%coins[n]==0) return amount/coins[n];
            else return 1e9;
        }
        if(dp[n][amount]!=-1) return dp[n][amount];
        int pick=1e9;
        if(coins[n]<=amount){
            pick=1+solve(coins,n,amount-coins[n],dp);
        }
        int notpick=solve(coins,n-1,amount,dp);
        return dp[n][amount]=min(pick,notpick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
        // int res=solve(coins,n-1,amount,dp);
        // if(res!=1e9) return res;
        // return -1;
        
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0) dp[0][i]=i/coins[0];
            else dp[0][i]=1e9;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=amount;j++){
                int pick=1e9;
                if(coins[i]<=j){
                    pick=1+dp[i][j-coins[i]];
                }
                int notpick=dp[i-1][j];
                dp[i][j]=min(pick,notpick);
            }
        }
        return (dp[n-1][amount]==1e9)? -1 : dp[n-1][amount];
    }
};