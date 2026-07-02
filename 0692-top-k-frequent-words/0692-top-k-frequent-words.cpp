class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n=words.size();
        unordered_map<string,int> mpp;
        for(string s:words){
            mpp[s]++;
        }
        
        vector<pair<int,string>> v;
        for(auto &it:mpp){
            v.push_back({it.second,it.first});
        }

        sort(v.begin(),v.end(),[&](pair<int,string> &a,pair<int,string> &b){
            if(a.first==b.first){
                return a.second<b.second;
            }
            return a.first>b.first;
        });

        vector<string> res;
        for(int i=0;i<k;i++){
            res.push_back(v[i].second);
        }

        return res;
    }
};