class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int median=0;
        if(n%2==0){
            median=(nums[n/2]+nums[n/2 -1])/2;
        }
        else median=nums[n/2];
        
        int totalmoves=0;
        for(int i=0;i<nums.size();i++){
            totalmoves+=abs(nums[i]-median);
        }

        return totalmoves;
    }
};