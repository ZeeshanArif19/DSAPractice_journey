class Solution {
public:
    int atmostk(vector<int> &nums,int k){
        int n=nums.size();
        unordered_map<int,int> mpp;
        
        int l=0,r=0;
        int count=0;

        while(r<n){
            mpp[nums[r]]++;
            while(mpp.size()>k){
                mpp[nums[l]]--;
                if(mpp[nums[l]]==0) mpp.erase(nums[l]);
                l++;
            }
            if(mpp.size()<=k){
                count+=(r-l+1);
            }
            r++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int a1=atmostk(nums,k);
        int a2=atmostk(nums,k-1);
        return a1-a2;
    }
};