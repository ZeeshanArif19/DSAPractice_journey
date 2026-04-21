class Solution {
public:
    int solve(vector<int> &nums,int i,int j,vector<vector<int>> &dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        int res=-1e9;
        for(int k=i;k<=j;k++){
            int currcoins=(nums[i-1]*nums[k]*nums[j+1]) + solve(nums,i,k-1,dp) + solve(nums,k+1,j,dp);
            res=max(res,currcoins);
        }
        return dp[i][j]=res;
    }
    int maxCoins(vector<int>& nums) {
        //pad array
        int n=nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);

        vector<vector<int>> dp(n+2,vector<int>(n+2,0));
        // return solve(nums,1,n,dp);
        
        for(int i=n;i>=1;i--){
            for(int j=1;j<=n;j++){
                if(i>j) continue;
                int res=-1e9;
                for(int k=i;k<=j;k++){
                    int currcoins=(nums[i-1]*nums[k]*nums[j+1]) + dp[i][k-1]+ dp[k+1][j];
                    res=max(res,currcoins);
                }
                dp[i][j]=res;
            }
        }
        return dp[1][n];
    }
};