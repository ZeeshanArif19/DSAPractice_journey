class Solution {
public:
    long long solve(vector<vector<int>>& questions,int i,vector<long long> &dp){
        if(i>=questions.size()) return 0;
        if(dp[i]!=-1) return dp[i];

        long long points=questions[i][0];
        long long brainpower=questions[i][1];
        long long sol=points + solve(questions,i+brainpower+1,dp);
        long long skip= solve(questions,i+1,dp);

        return dp[i]=max(sol,skip);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        vector<long long> dp(n+1,-1);
        return solve(questions,0,dp);
    }
};