class Solution {
public:
    void rotate90(vector<vector<int>>& mat,int &n){
        for(int i=0;i<n;i++){  //transpose
            for(int j=i+1;j<n;j++){
                swap(mat[i][j],mat[j][i]);
            }
        }
        reverse(mat.begin(),mat.end());
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n=mat.size();
        if(mat==target) return true;
        for(int k=0;k<3;k++){
            rotate90(mat,n);
            if(mat==target) return true;
        }
        return false;
    }
};