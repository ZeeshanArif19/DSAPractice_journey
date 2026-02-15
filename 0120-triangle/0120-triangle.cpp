class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        // vector<vector<int>> dp(n+1,vector<int>(n+1,1e9));
        vector<int> dp(n+1);
        
        // for(int j=0;j<n;j++) dp[n][j]=0;
        
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=i;j++){
                dp[j]=triangle[i][j]+ min(dp[j],dp[j+1]);
                // dp[i][j]=triangle[i][j]+min(dp[i+1][j],dp[i+1][j+1]);
            }
        }
        return dp[0];
    }
};