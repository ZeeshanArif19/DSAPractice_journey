class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        int maxFreq=0;
        unordered_map<int,int> mpp;
        for(int &it:nums){
            mpp[it]++;
            maxFreq=max(maxFreq,mpp[it]);
        }
        return nums.size()-maxFreq;
    }
};