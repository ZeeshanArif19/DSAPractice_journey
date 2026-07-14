class Solution {
public:
    bool solve(vector<int>& matchsticks,vector<int>& dp,int mask,int currsum,int target,int k){
        if(k==1) return true;
        
        if(currsum==target){
            return solve(matchsticks,dp,mask,0,target,k-1);
        }
        if(dp[mask]!=-1) return dp[mask];
        
        for(int i=0;i<matchsticks.size();i++){
            if((mask & (1<<i))!=0 && currsum+matchsticks[i]<=target){
                
                int nextmask=mask ^ (1<<i);
                if(solve(matchsticks,dp,nextmask,currsum+matchsticks[i],target,k)){
                    return dp[mask]=1;
                }
            }
        }
        return dp[mask]=0;
    }
    bool makesquare(vector<int>& matchsticks) {
        int n=matchsticks.size();
        int sum=accumulate(matchsticks.begin(),matchsticks.end(),0);
        if(sum%4!=0) return false;
        
        int target=sum/4;
        int initialMask=(1<<(n+1)) -1; //set all bits to on
        vector<int> dp(initialMask+1,-1);

        return solve(matchsticks,dp,initialMask,0,target,4);
    }
};