class Solution {
public:
    int helper(vector<int> &nums,int bound){
        int n=nums.size();
        deque<int> maxD;
        int count=0;
        int i=0;
        for(int j=0;j<n;j++){
            while(!maxD.empty() && nums[j]>=nums[maxD.back()]){
                maxD.pop_back();
            }
            maxD.push_back(j);

            while(i<=j){
                int currmax=nums[maxD.front()];
                if(currmax>bound){
                    i++;
                    if(!maxD.empty() && i>maxD.front()) maxD.pop_front();
                }
                else break;
            }
            count+=(j-i+1);
        }
        return count;
    }
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {

        return helper(nums,right)-helper(nums,left-1);
    }
};