class Solution {
public:
    bool isValid(vector<int>& nums,int k,int mid){
        int robCount=0;
        int i=0;
        while(i<nums.size()){
            if(nums[i]<=mid){
                robCount++;
                i=i+2;
            }
            else i=i+1;
        }
        return robCount>=k;
    }
    int minCapability(vector<int>& nums, int k) {
        int l=*min_element(nums.begin(),nums.end());
        int r=*max_element(nums.begin(),nums.end());
        int ans=0;
        
        while(l<=r){
            int mid=l+(r-l)/2;
            if(isValid(nums,k,mid)){
                r=mid-1;
                ans=mid;
            }
            else l=mid+1;
        }
        return ans;
    }
};