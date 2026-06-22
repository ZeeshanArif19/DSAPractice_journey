class Solution {
public:
    int helper(vector<int>& nums, int target,bool searchFirst){
        int n=nums.size();
        int l=0;
        int r=n-1;
        int ans=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]==target){
                ans=mid;
                if(searchFirst) r=mid-1;
                else l=mid+1;
            }
            else if(nums[mid]<target){
                l=mid+1;
            }
            else r=mid-1;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return {helper(nums,target,true),helper(nums,target,false)};
    }
};