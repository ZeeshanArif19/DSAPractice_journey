class Solution {
public:
    int countAtmostK(vector<int> &nums,int k){
        int n=nums.size();
        unordered_map<int,int> mpp;
        int count=0;
        int i=0,j=0;
        
        while(j<n){
            mpp[nums[j]]++;
            while(mpp.size()>k){
                mpp[nums[i]]--;
                if(mpp[nums[i]]==0) mpp.erase(nums[i]);
                i++;
            }
            if(mpp.size()<=k) count+=(j-i+1);
            j++; 
        }
        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int countAtK=countAtmostK(nums,k);
        int countAtKminus1=countAtmostK(nums,k-1);
        return countAtK-countAtKminus1;
    }
};