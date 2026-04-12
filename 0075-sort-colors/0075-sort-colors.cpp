class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0,mid=0,high=nums.size()-1;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[mid],nums[low]);
                low++;
                mid++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else if(nums[mid]==2){
                swap(nums[mid],nums[high]);
                high--;
            }
        }
        // int ones=0;
        // int twos=0;
        // int zeros=0;
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]==0) zeros++;
        //     if(nums[i]==1) ones++;
        //     if(nums[i]==2) twos++;
        // }
        // int k=0;
        // while(zeros!=0){
        //     nums[k++]=0;
        //     zeros--;
        // }
        // while(ones!=0){
        //     nums[k++]=1;
        //     ones--;
        // }
        // while(twos!=0){
        //     nums[k++]=2;
        //     twos--;
        // }
 
    }
};