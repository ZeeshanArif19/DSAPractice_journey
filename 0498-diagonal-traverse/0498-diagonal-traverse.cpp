class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m=mat.size();
        unordered_map<int,vector<int>> mpp;  //sum of i+j ---> list of val
        int maxsum=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<mat[i].size();j++){
                mpp[i+j].push_back(mat[i][j]);
                maxsum=max(maxsum,i+j);
            }
        }

        vector<int> res;
        for(int s=0;s<=maxsum;s++){
            if(s%2==0) reverse(mpp[s].begin(),mpp[s].end());

            for(int &val:mpp[s]){
                res.push_back(val);
            }
        }
        return res;
    }
};