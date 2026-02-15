class Solution {
public:
    int solve(vector<vector<char>>& matrix,int i,int j,int m,int n,vector<vector<int>>& dp){
        if(i==m || j==n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        if(matrix[i][j]=='0') return dp[i][j]=0;

        int minsquare=min({solve(matrix,i+1,j+1,m,n,dp),solve(matrix,i+1,j,m,n,dp),solve(matrix,i,j+1,m,n,dp)});
        return dp[i][j]=1+minsquare;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        
        int maxSide=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || j==0 || matrix[i][j]=='0'){
                    dp[i][j]=matrix[i][j]-'0';
                }
                else{
                    dp[i][j]=min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]}) +1;
                }
                maxSide=max(maxSide,dp[i][j]);
            }
        }

        return maxSide*maxSide;
    }
};