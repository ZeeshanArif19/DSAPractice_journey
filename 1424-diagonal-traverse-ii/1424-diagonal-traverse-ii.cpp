class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int m=nums.size();
        //numbers with equal sums of row and column indexes belong to the same diagonal.
        vector<array<int,3>> sumTup; //store them in form {sum,row,val}
        for(int i=0;i<m;i++){
            int n=nums[i].size();
            for(int j=0;j<n;j++){
                sumTup.push_back({i+j,i,nums[i][j]});
            }
        }

        auto cmp=[&](array<int,3>& a,array<int,3>& b){ //sort them on sum if sum equal-->sort row DESC
            if(a[0]==b[0]) return a[1]>b[1];
            return a[0]<b[0];
        };
        sort(sumTup.begin(),sumTup.end(),cmp);
        
        vector<int> res;
        for(int i=0;i<sumTup.size();i++){
            res.emplace_back(sumTup[i][2]);
        }

        return res;
    }
};