class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int> diffArr(n+1,0);
        
        for(int i=0;i<queries.size();i++){
            int l=queries[i][0];
            int r=queries[i][1];
            
            diffArr[l]+=1;
            diffArr[r+1]-=1;
        }
        
        int val=0;
        for(int i=0;i<n;i++){
            val+=diffArr[i];
            diffArr[i]=val;
            if(diffArr[i]<nums[i]) return false;
        }
        return true;
    }
};