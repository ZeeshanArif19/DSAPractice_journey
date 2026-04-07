class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        
        int l=0;
        int r=0;
        int maxcount=0;
        long long sum=0;

        while(r<n){
            int target=nums[r];
            sum+=nums[r];
            int window=r-l+1;

            while((window*1LL*target)-sum>k){
                sum-=nums[l];
                l++;
                window=r-l+1;
            }
            r++;
            maxcount=max(maxcount,window);
        }
        return maxcount;
    }
};