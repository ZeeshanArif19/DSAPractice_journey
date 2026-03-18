class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n=nums.size();
        if(n<=4) return 0;
        sort(nums.begin(),nums.end());
        int mindiff=0;
        
        //remove 3smallest,2smallest+1largest,1smallest+2largest,3largest
        mindiff=min({nums[n-1]-nums[3],nums[n-2]-nums[2],nums[n-3]-nums[1],nums[n-4]-nums[0]});
        return mindiff;
    }
};