class Solution {
public:
    void merge(vector<int> &nums,int low,int mid,int high,int &cnt){
        int right=mid+1;
        for(int i=low;i<=mid;i++){  //two pointer count the number of reverse pairs in the two sorted halves of the array
            while(right<=high && nums[i]>2*1LL*nums[right]){
                right++;
            }
            cnt+=(right-(mid+1)); //cause every element from mid+1 to right is valid if right is valid
        }

        vector<int> temp;
        int i=low;
        int j=mid+1;

        while(i<=mid && j<=high){
            if(nums[i]<=nums[j]){
                temp.push_back(nums[i]);
                i++;
            }
            else{
                temp.push_back(nums[j]);
                j++;
            }
        }
        while(i<=mid) temp.push_back(nums[i++]);
        while(j<=high) temp.push_back(nums[j++]);

        for(int k=0;k<temp.size();k++){
            nums[low+k]=temp[k];
        }
    }
    void mergeSort(vector<int> &nums,int low,int high,int &cnt){
        if(low>=high) return;
        
        int mid=low+(high-low)/2;
        mergeSort(nums,low,mid,cnt);
        mergeSort(nums,mid+1,high,cnt);
        merge(nums,low,mid,high,cnt);
    }
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        mergeSort(nums,0,n-1,cnt);
        return cnt;
    }
};