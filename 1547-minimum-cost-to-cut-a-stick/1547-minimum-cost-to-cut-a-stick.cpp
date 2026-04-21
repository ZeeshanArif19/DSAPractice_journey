class Solution {
public:
    int solve(vector<int> &cuts,int i,int j,vector<vector<int>> &dp){
        if(i+1>=j) return 0; //if j-i<=1 these is no room for a cut so cost in 0
        if(dp[i][j]!=-1) return dp[i][j];
        
        int res=1e9;
        for(int k=i+1;k<j;k++){
            int currcost=(cuts[j]-cuts[i]) + solve(cuts,i,k,dp) + solve(cuts,k,j,dp);
            res=min(res,currcost);
        }
        return dp[i][j]=res;
    }
    
    int minCost(int n, vector<int>& cuts) {
        //sort and pad
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());

        int m=cuts.size();
        vector<vector<int>> dp(m,vector<int>(m,-1));

        return solve(cuts,0,m-1,dp);
    }
};