class Solution {
public:
    bool solve(int mask,int n,int tot,vector<int> &dp){
        if(dp[mask]!=-1) return dp[mask];

        for(int i=1;i<=n;i++){  //try every available number
            if((mask & (1<<i))!=0){ //if available
                if(i>=tot) return dp[mask]=true;  //if picking i instantly clears the target we win

                int nextmask= mask ^ (1<<i); //otherwise we use i and see if the opponent looses, we flip the bit
                
                if(solve(nextmask,n,tot-i,dp)==false){
                    return dp[mask]=true;  //if the opponent looses that means we win
                }
            }
        }
        return dp[mask]=false; //if we looped through all the numbers and none of them led to the opponents loss
    }
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if(desiredTotal<=0) return true;
        int totsum=(maxChoosableInteger*(maxChoosableInteger+1))/2;
        if(totsum<desiredTotal) return false;

        int mask=(1 << maxChoosableInteger+1) - 1;
        vector<int> dp(mask+1,-1);
        return solve(mask,maxChoosableInteger,desiredTotal,dp);
    }
};