class Solution {
public:
    vector<vector<int>> res;
    void solve(vector<int>& nums,vector<int> &temp,vector<bool> &vis,int start){
        if(temp.size()==nums.size()){
            res.push_back(temp);
            return;
        }
        for(int i=start;i<nums.size();i++){
            if(!vis[i]){
                vis[i]=1;
                temp.push_back(nums[i]);
                solve(nums,temp,vis,start);
                vis[i]=0;
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums){
        vector<int> temp;
        vector<bool> vis(nums.size(),0);
        solve(nums,temp,vis,0);
        return res;
    }
};