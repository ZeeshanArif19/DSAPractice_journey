class Solution {
public:
    void dfs(vector<vector<int>>& image,vector<vector<int>> &ans,int sr,int sc,int color,
     int iniColor,vector<int> &delRow,vector<int> &delCol){
        
        ans[sr][sc]=color;
        int n=image.size();
        int m=image[0].size();
        for(int i=0;i<4;i++){
            int nrow=sr+delRow[i];
            int ncol=sc+delCol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m
                && image[nrow][ncol]==iniColor && ans[nrow][ncol]!=color){
                    dfs(image,ans,nrow,ncol,color,iniColor,delRow,delCol);
                }
        }
     }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int iniColor=image[sr][sc];
        vector<vector<int>> ans=image;
        vector<int> delRow={1,-1,0,0};
        vector<int> delCol={0,0,1,-1};
        dfs(image,ans,sr,sc,color,iniColor,delRow,delCol);

        return ans;
    }
};