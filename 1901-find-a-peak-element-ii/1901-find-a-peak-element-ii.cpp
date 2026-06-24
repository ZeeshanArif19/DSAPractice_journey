class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        int low_col=0;
        int high_col=n-1;

        while(low_col<=high_col){
            int mid_col=(low_col+high_col)/2;

            int maxrow=0;
            for(int i=0;i<m;i++){
                if(mat[maxrow][mid_col]<mat[i][mid_col]){
                    maxrow=i;
                }
            }

            int leftval=(mid_col-1>=0)?mat[maxrow][mid_col-1]:-1;
            int rightval=(mid_col+1<n)?mat[maxrow][mid_col+1]:-1;

            if(mat[maxrow][mid_col]>leftval && mat[maxrow][mid_col]>rightval){
                return {maxrow,mid_col};
            }
            else if(mat[maxrow][mid_col]<leftval){
                high_col=mid_col-1;
            }
            else{
                low_col=mid_col+1;
            }
        }
        return {-1,-1};
    }
};