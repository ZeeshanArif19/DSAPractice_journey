class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        auto cmp=[&](string &a,string &b){
            if(a.size()!=b.size()) return a.size()<b.size();
            return a<b;
        };
        priority_queue<string,vector<string>,decltype(cmp)> pq(cmp);
        for(string &it:nums) pq.push(it);
        for(int i=0;i<k-1;i++) pq.pop();
        return pq.top();
    }
};