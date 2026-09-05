class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> maxi(n);
        vector<int> mini(n);
        int small=INT_MAX;
        int big=0;

        for(int i=0;i<n;i++){
            big=max(big,nums[i]);
            maxi[i]=big;
            small=min(small,nums[n-i-1]);
            mini[n-i-1]=small;
        }
        for(int i=0;i<n;i++){
            if(maxi[i]-mini[i]<=k) return i;
        }
        return -1;
    }
};