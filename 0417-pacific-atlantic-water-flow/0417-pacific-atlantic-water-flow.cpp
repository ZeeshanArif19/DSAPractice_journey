class Solution {
public:
    void dfs(vector<vector<int>>& heights,vector<vector<bool>>& vis,int i,int j){
        int n=heights.size();
        int m=heights[0].size();
        vis[i][j]=true;
        
        vector<int> delRow={1,-1,0,0};  //standard flood fill
        vector<int> delCol={0,0,1,-1};
        for(int k=0;k<4;k++){
            int nr=i+delRow[k];
            int nc=j+delCol[k];
            if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && heights[nr][nc]>=heights[i][j]){
                dfs(heights,vis,nr,nc);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<bool>> atlantic(n,vector<bool>(m,false));
        vector<vector<bool>> pacific(n,vector<bool>(m,false));
        //call dfs for pacific
        for(int i=0;i<m;i++) dfs(heights,pacific,0,i); //top
        for(int i=0;i<n;i++) dfs(heights,pacific,i,0); //left
        //call dfs for atlantic
        for(int i=0;i<n;i++) dfs(heights,atlantic,i,m-1); //right
        for(int i=0;i<m;i++) dfs(heights,atlantic,n-1,i); //bottom

        vector<vector<int>> res;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pacific[i][j]==true && atlantic[i][j]==true){  //if both visited then that is our answer
                    res.push_back({i,j});
                }
            }
        }
        return res;
    }
};