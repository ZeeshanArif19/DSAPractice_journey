class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for(int &i:nums){
            mpp[i]++;
            if(mpp[i]>2) return false;
        }
        return true;
    }
};