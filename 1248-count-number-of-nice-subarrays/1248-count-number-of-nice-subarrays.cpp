class Solution {
public:
    int atmostKodd(vector<int>& nums, int k){
        int i=0,j=0;
        int oddCnt=0;
        int niceCnt=0;

        while(j<nums.size()){
            if(nums[j]%2!=0) oddCnt++;
            while(oddCnt>k){
                if(nums[i]%2!=0) oddCnt--;
                i++;
            }
            if(oddCnt<=k) niceCnt+=(j-i+1);
            j++;
        }
        return niceCnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmostKodd(nums,k)-atmostKodd(nums,k-1);
    }
};