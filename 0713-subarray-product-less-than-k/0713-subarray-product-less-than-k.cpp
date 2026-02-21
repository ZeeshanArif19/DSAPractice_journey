class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0,j=0;
        int pro=1;
        int count=0;

        if(k==0 || k==1) return 0;
        
        while(j<n){
            pro*=nums[j];
            while(pro>=k){
                pro/=nums[i];
                i++;
            }

            count+=(j-i+1);
            j++;
        }
        return count;
    }
};