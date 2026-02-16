class Solution {
public:
    bool solve(vector<int> & stones,int i,int k,vector<vector<int>> &dp,unordered_map<int,int> &mpp){
        if(i>=stones.size()-1) return true;
        if(dp[i][k]!=-1) return dp[i][k];

        bool op1=false;
        bool op2=false;
        bool op3=false;

        int next_pos=stones[i]+(k+1);
        if(mpp.count(next_pos)){
            op1=solve(stones,mpp[next_pos],k+1,dp,mpp); //index,distance
        }
        
        next_pos=stones[i]+k;
        if(k>0 && mpp.count(next_pos)){
            op2=solve(stones,mpp[next_pos],k,dp,mpp);
        }

        next_pos=stones[i]+(k-1);
        if((k-1)>0 && mpp.count(next_pos)){
            op3=solve(stones,mpp[next_pos],k-1,dp,mpp);
        }
        
        return dp[i][k]= op1 || op2 || op3;
    }
    bool canCross(vector<int>& stones){
        if(stones[1]!=1) return false;
        int n=stones.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        unordered_map<int,int> mpp; //stonepos,stoneindex
        for(int i=0;i<n;i++){
            mpp[stones[i]]=i;
        }
        return solve(stones,1,1,dp,mpp);
    }
};