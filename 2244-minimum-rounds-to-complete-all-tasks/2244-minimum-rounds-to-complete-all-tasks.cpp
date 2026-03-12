class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> mpp;
        for(int &i:tasks) mpp[i]++;
        
        int rounds=0;
        for(auto &it:mpp){
            int freq=it.second;
            if(freq<2) return -1;
            
            rounds+=(freq+2)/3;
        }
        return rounds;
    }
};