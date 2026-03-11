class Solution {
public:
    void solve(vector<vector<int>> &res,vector<int> &temp,int &n,int k,int start){
        if(temp.size()==k){
            res.push_back(temp);
            return;
        }
        for(int i=start;i<=n;i++){
            temp.push_back(i);
            solve(res,temp,n,k,i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        vector<vector<int>> res;
        solve(res,temp,n,k,1);
        return res;
    }
};