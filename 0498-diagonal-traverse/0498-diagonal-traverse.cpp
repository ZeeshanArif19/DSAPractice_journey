class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        // unordered_map<int,vector<int>> mpp;  //sum of i+j ---> list of val
        vector<vector<int>> buckets(m+n-1);
        int maxsum=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                buckets[i+j].push_back(mat[i][j]);
                maxsum=max(maxsum,i+j);
            }
        }

        vector<int> res;
        for(int s=0;s<=maxsum;s++){
            if(s%2==0){
                for(int i=buckets[s].size()-1;i>=0;i--){
                    res.push_back(buckets[s][i]);
                }
            }
            else{
                for(int i=0;i<buckets[s].size();i++){
                    res.push_back(buckets[s][i]);
                }
            }
        }
        return res;
    }
};