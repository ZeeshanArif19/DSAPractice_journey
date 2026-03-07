class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int,vector<int>> mpp; //element,indexes
        set<int> s;  //element
        for(int i=0;i<arr.size();i++){
            mpp[arr[i]].push_back(i);
            s.insert(arr[i]);
        }

        vector<int> res(arr.size());
        int rank=1;
        for(auto &i:s){
            for(auto &ind:mpp[i]){
                res[ind]=rank;
            }
            rank++;
        }
        return res;
    }
};