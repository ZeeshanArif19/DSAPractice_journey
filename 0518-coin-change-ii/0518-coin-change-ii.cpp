class Solution {
public:
    int solve(vector<int>& coins,vector<vector<long long>> &dp,int i,int amount){
        if(i==coins.size() || amount<0) return 0;
        if(amount==0) return 1;
        if(dp[i][amount]!=-1) return dp[i][amount];

        long long pick=solve(coins,dp,i,amount-coins[i]);
        long long notpick=solve(coins,dp,i+1,amount);

        return dp[i][amount]=pick+notpick;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        // vector<vector<unsigned long long>> dp(n+1,vector<unsigned long long>(amount+1,0));
        // vector<unsigned long long> prev(amount+1);
        // vector<unsigned long long> curr(amount+1);

        // int res=solve(coins,dp,0,amount);
        // return res;

        // for(int i=0;i<n;i++) dp[i][0]=1;
        // curr[0]=1;
        // for(int i=n-1;i>=0;i--){
        //     for(int j=1;j<=amount;j++){
        //         unsigned long long pick=0;
        //         if(j>=coins[i]){
        //             pick=curr[j-coins[i]];
        //         }
        //         unsigned long long notpick=prev[j];
        //         curr[j]=pick+notpick;
        //     }
        //     prev=curr;
        // }
        // return prev[amount];

        //1d optimization
        vector<unsigned long long> dp(amount+1,0);
        dp[0]=1;
        for(int i=n-1;i>=0;i--){
            for(int j=coins[i];j<=amount;j++){
                dp[j]+=dp[j-coins[i]];
            }
        }
        return dp[amount];
    }
};