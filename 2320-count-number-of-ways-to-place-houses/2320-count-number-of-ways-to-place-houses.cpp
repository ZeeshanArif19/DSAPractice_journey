class Solution {
public:
    int MOD=1e9+7;
    int fibo(long long n,vector<int> &dp){
        if(n==0) return 1;
        if(n==1) return 2;
        if(dp[n]!=-1) return dp[n];
        
        return dp[n]=(fibo(n-1,dp)+fibo(n-2,dp))%MOD;
        
    }
    int countHousePlacements(int n) {
        vector<long long> dp(n+1,-1);
        // long long oneway=fibo(n,dp);
        // return (oneway*oneway)%MOD;

        dp[0]=1;
        dp[1]=2;
        for(int i=2;i<=n;i++){
            dp[i]=(dp[i-1]+dp[i-2])%MOD;
        }
        return (dp[n]*dp[n])%MOD;
    }
};