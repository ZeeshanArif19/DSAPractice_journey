class Solution {
public:
    void merge(vector<int>& nums,int left,int mid,int right){
        vector<int> temp;
        int i=left;
        int j=mid+1;

        while(i<=mid && j<=right){
            if(nums[i]<=nums[j]){
                temp.emplace_back(nums[i++]);
            }
            else{
                temp.emplace_back(nums[j++]);
            }
        }
        while(i<=mid) temp.emplace_back(nums[i++]);
        while(j<=right) temp.emplace_back(nums[j++]);

        for(int k=0;k<temp.size();k++){
            nums[left+k]=temp[k];
        }
    }
    void mergeSort(vector<int>& nums,int left,int right){
        if(left>=right) return;
        
        int mid=left+(right-left)/2;
        mergeSort(nums,left,mid);
        mergeSort(nums,mid+1,right);
        merge(nums,left,mid,right);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        mergeSort(nums,0,n-1);
        return nums;
    }
};