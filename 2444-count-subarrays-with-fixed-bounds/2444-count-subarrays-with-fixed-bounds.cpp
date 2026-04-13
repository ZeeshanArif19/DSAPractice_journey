class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n=nums.size();
        long long lastmin=-1, lastmax=-1, lastbad=-1;
        long long count=0;

        for(int i=0;i<n;i++){
            if(nums[i]<minK || nums[i]>maxK) lastbad=i;
            
            if(nums[i]==minK) lastmin=i;
            if(nums[i]==maxK) lastmax=i;
            
            long long validrange= min(lastmin,lastmax) -lastbad;
            if(validrange>0){
                count+=validrange;
            }
        }
        return count;
    }
};