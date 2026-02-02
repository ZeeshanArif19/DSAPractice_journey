class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> ans;
        int toprow=0,bottomrow=n-1;
        int leftcol=0,rightcol=m-1;

        while(toprow<=bottomrow && leftcol<=rightcol){
            for(int i=leftcol;i<=rightcol;i++){
                ans.push_back(matrix[toprow][i]);
            }
            toprow++;
            for(int i=toprow;i<=bottomrow;i++){
                ans.push_back(matrix[i][rightcol]);
            }
            rightcol--;
            if(toprow<=bottomrow){
                for(int i=rightcol;i>=leftcol;i--){
                    ans.push_back(matrix[bottomrow][i]);
                }
                bottomrow--;
            }
            if(leftcol<=rightcol){
                for(int i=bottomrow;i>=toprow;i--){
                    ans.push_back(matrix[i][leftcol]);
                }
                leftcol++;
            }
        }
        return ans;
    }
};