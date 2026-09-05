class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> s;
        int i=0;
        int j=0;
        int maxsum=0;
        int currsum=0;

        while(j<n){
            while(s.find(nums[j])!=s.end()){
                currsum-=nums[i];
                s.erase(nums[i]);
                i++;
            }
            if(s.find(nums[j])==s.end()){
                currsum+=nums[j];
                s.insert(nums[j]);
                j++;
            }
            maxsum=max(maxsum,currsum);
        }
        return maxsum;
    }
};