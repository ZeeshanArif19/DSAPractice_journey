class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int,vector<int>> mpp;   //groupsize,index
        for(int i=0;i<groupSizes.size();i++){
            mpp[groupSizes[i]].push_back(i);
        }
        vector<vector<int>> res;
        for(auto &it:mpp){
            vector<int> temp;
            vector<int> &peoples=it.second;
            int size=it.first;
            
            for(int &people:peoples){
                temp.push_back(people);
                if(temp.size()==size){
                    res.push_back(temp);
                    temp.clear();
                }
            }
        }
        return res;
    }
};