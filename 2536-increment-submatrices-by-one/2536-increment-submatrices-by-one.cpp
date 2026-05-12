class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> diffMat(n,vector<int>(n,0));
        
        for(int i=0;i<queries.size();i++){
            int r1=queries[i][0];
            int c1=queries[i][1];
            int r2=queries[i][2];
            int c2=queries[i][3];

            diffMat[r1][c1]+=1;
            if(c2<n-1){
                diffMat[r1][c2+1]-=1;
            }
            if(r2<n-1){
                diffMat[r2+1][c1]-=1;
            }
            if(r2<n-1 && c2<n-1){
                diffMat[r2+1][c2+1]+=1;
            }
        }
        
        for(int i=0;i<n;i++){  //row prefix
            for(int j=1;j<n;j++){
                diffMat[i][j]=diffMat[i][j-1]+diffMat[i][j];
            }
        }
        for(int i=1;i<n;i++){  //col prefix
            for(int j=0;j<n;j++){
                diffMat[i][j]=diffMat[i-1][j]+diffMat[i][j];
            }
        }

        return diffMat;
    }
};