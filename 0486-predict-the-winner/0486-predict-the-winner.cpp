class Solution {
public:
    int solve(vector<int> &nums,int left,int right){
        if(left==right) return nums[left];
        
        int leftop=nums[left]-solve(nums,left+1,right);
        int rightop=nums[right]-solve(nums,left,right-1);
        
        return max(leftop,rightop);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        int left=0;
        int right=n-1;
        // int netscore=solve(nums,left,right);
        //tabulation
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){ //left cannot be greater than right so we start right from left
                if(i==j) {
                    dp[i][j]=nums[i];
                    continue;
                }
                int leftop=nums[i]-dp[i+1][j];
                int rightop=nums[j]-dp[i][j-1];
                
                dp[i][j]=max(leftop,rightop);
            }
        }

        return dp[0][n-1]>=0;
    }
};