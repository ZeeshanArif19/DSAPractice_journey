class Solution {
public:
    // bool isPalindrome(string &temp,int i,int j){
    //     while(i<j){
    //         if(temp[i]!=temp[j]) return false;
    //         i++;
    //         j--;
    //     }
    //     return true;
    // }
    // int solve(string &s,int i,int n,vector<int> &dp){
    //     if(i==n) return 0;
    //     if(dp[i]!=-1) return dp[i];

    //     int mincost=1e9;
    //     for(int j=i;j<n;j++){
    //         if(isPalindrome(s,i,j)){
    //             int cost=1+solve(s,j+1,n,dp);
    //             mincost=min(mincost,cost);
    //         }
    //     }
    //     return dp[i]=mincost;  
    // }
    int minCut(string s) {
        int n=s.size();
        vector<vector<bool>> isPal(n+1,vector<bool>(n+1,false));
        vector<int> dp(n+1);
        // return solve(s,0,n,dp) - 1; //because the code does a partition at the very end of the string

        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(s[i]==s[j]){
                    if(j-i<=2) isPal[i][j]=true;
                    else isPal[i][j]=isPal[i+1][j-1];
                }
            }
        }

        dp[n]=0;
        for(int i=n-1;i>=0;i--){
            int mincost=1e9;
            for(int j=i;j<n;j++){
                if(isPal[i][j]){
                    int cost=1+dp[j+1];
                    mincost=min(cost,mincost);
                }
                dp[i]=mincost;
            }
        }
        return dp[0]-1;
    }
};