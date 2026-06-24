class Solution {
public:
    bool isValid(vector<int>& nums,int threshold,int div){
        int sum=0;
        
        for(int i=0;i<nums.size();i++){
            sum+=ceil((double)nums[i]/div);
        }
        return sum<=threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int l=1;
        int r=*max_element(nums.begin(),nums.end());
        int ans=-1;

        while(l<=r){
            int mid=l+(r-l)/2;
            if(isValid(nums,threshold,mid)){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};