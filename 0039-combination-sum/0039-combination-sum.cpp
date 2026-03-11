class Solution {
public:
    void solve(vector<int> &candidates,vector<vector<int>> &res,vector<int> &temp,int target,int start,int sum){
        if(sum==target){
            res.push_back(temp);
            return;
        }
        if(sum>target) return;

        for(int i=start;i<candidates.size();i++){
            temp.push_back(candidates[i]);
            solve(candidates,res,temp,target,i,sum+candidates[i]);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        solve(candidates,res,temp,target,0,0);
        return res;
    }
};