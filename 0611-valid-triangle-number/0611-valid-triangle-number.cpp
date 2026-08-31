class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n=nums.size();
        int combo=0;
        sort(nums.begin(),nums.end());

        for(int i=n-1;i>=0;i--){
            int c=nums[i];
            int start=0;
            int end=i-1;
            while(start<end){
                if(nums[start]+nums[end]>c){
                    combo+=(end-start);
                    end--;
                }
                else{
                    start++;
                }
            }
        }
        return combo;
    }
};