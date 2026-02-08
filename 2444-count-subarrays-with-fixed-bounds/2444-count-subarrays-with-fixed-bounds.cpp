class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long count=0;
        long long lastmax=-1, lastmin=-1, lastbad=-1;
        int n=nums.size();

        for(int i=0;i<n;i++){
            if(nums[i]<minK || nums[i]>maxK) lastbad=i;

            if(nums[i]==minK) lastmin=i;
            if(nums[i]==maxK) lastmax=i;

            long long validrange=min(lastmin,lastmax) -lastbad;

            if(validrange>0) count+=validrange;
        }
        return count;
    }
};