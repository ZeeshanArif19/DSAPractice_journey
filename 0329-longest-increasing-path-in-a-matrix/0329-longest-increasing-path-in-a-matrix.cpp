class Solution {
public:
    int dfs(vector<vector<int>>& matrix,vector<vector<int>> &dp,int &m,int &n,int i,int j){

        if(dp[i][j]!=-1) return dp[i][j];
        int maxlen=1;
        
        int dr[4]={1,-1,0,0};
        int dc[4]={0,0,1,-1};
        
        for(int k=0;k<4;k++){
            int nr=i+dr[k];
            int nc=j+dc[k];
            if(nr>=0 && nr<m && nc>=0 && nc<n && matrix[nr][nc]>matrix[i][j]){
                maxlen=max(maxlen,1+dfs(matrix,dp,m,n,nr,nc));
            }
        }
        return dp[i][j]=maxlen;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int maxlen=0;

        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                maxlen=max(maxlen,dfs(matrix,dp,m,n,i,j));
            }
        }

        return maxlen;
    }
};