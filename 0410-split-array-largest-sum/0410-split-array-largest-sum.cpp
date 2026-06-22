class Solution {
public:
    bool isValid(vector<int> &nums,int k,int mid){
        int count=1;
        int sum=0;
        
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]<=mid){
                sum+=nums[i];
            }
            else{
                count++;
                sum=nums[i];
            }
        }
        return count<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int l=*max_element(nums.begin(),nums.end());
        int r=accumulate(nums.begin(),nums.end(),0);
        int ans=-1;
        
        while(l<=r){
            int mid=l+(r-l)/2;
            if(isValid(nums,k,mid)){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};