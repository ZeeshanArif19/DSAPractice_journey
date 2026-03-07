class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int> mp; //num,count
        for(int &i:nums){
            mp[i]++;
        }
        
        for(auto &it:mp){
            int val=it.first;
            int count=it.second;
            if(count>0){
                for(int i=0;i<k;i++){
                    if(mp[val+i]<count) return false;
                    mp[val+i]-=count;
                }
            }
        }
        return true;
    }
};