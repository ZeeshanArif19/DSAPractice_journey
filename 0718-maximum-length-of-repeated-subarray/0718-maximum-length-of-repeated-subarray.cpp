class Solution {
public:
    // int solve(vector<int>& nums1, vector<int>& nums2,int i,int j){
    //     if(i<0 || j<0) return 0;
        
    //     if(nums1[i]==nums2[j]){
    //         return 1+solve(nums1,nums2,i-1,j-1);
    //     }
    //     else{
    //         return max(solve(nums1,nums2,i-1,j),solve(nums1,nums2,i,j-1));
    //     }
    // }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        int maxlen=0;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(nums1[i-1]==nums2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                    maxlen=max(maxlen,dp[i][j]);
                }
            }
        }
        return maxlen;
    }
};