class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        vector<string> res;

        while(i<n){
            int start=nums[i];
            while(i<n-1 && nums[i+1]-1==nums[i]){
                i++;
            }
            if(start!=nums[i]) res.push_back(to_string(start)+"->"+to_string(nums[i]));
            else res.push_back(to_string(start));
            i++;
        }
        return res;
    }
};