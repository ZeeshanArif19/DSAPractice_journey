class Solution {
public:
    int solve(int n,vector<int> &squares,int size,vector<vector<int>> &dp){
        if(size==0){
            if(n%squares[size]==0) return n/squares[size];
            else return 1e9;
        }
        if(dp[size][n]!=-1) return dp[size][n];

        int pick=1e9;
        if(squares[size]<=n){
            pick=1+solve(n-squares[size],squares,size,dp);
        }
        int notpick=solve(n,squares,size-1,dp);
        
        return dp[size][n]=min(pick,notpick);
    }
    int numSquares(int n) {
        vector<int> squares;
        for(int i=1;i*i<=n;i++){
            if(i*i<=n) squares.push_back(i*i); //store all the perfect squares less than n in an array
        }
        int size=squares.size();
        vector<vector<int>> dp(size+1,vector<int>(n+1,-1));
        return solve(n,squares,size-1,dp); //run simple coin change on this array
    }
};