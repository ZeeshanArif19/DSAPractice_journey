class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        
        for(int startcol=0;startcol<n;startcol++){ //check from toprow
            int i=0;
            int j=startcol;
            while(i<m-1 && j<n-1){
                if(matrix[i][j]!=matrix[i+1][j+1]) return false;
                i++;
                j++;
            }
        }

        for(int startcol=1;startcol<m;startcol++){ //check from left col
            int i=startcol;
            int j=0;
            while(i<m-1 && j<n-1){
                if(matrix[i][j]!=matrix[i+1][j+1]) return false;
                i++;
                j++;
            }
        }
        return true;
    }
};