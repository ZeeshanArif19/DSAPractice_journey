class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int res=*max_element(nums.begin(),nums.end()); //to handle case when only one element is in the array or when all the elements in the array are negative
        int currMax=1, currMin=1; //currmax->max product ending at the current pos, currmin->min pro ..
        //currmin-> crucial cause  a -ve number X -ve number give +ve number
        for(int i=0;i<n;i++){
            int temp=currMax*nums[i];
            
            currMax=max({temp,currMin*nums[i],nums[i]}); //nums[i] in case a fresh start is better
            currMin=min({temp,currMin*nums[i],nums[i]});

            res=max(res,currMax);
        }
        return res;
    }
};