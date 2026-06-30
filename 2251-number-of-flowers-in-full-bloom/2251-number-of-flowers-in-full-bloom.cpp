class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int n=flowers.size();
        map<int,int> mp; //position,change
        mp[0]=0; //prevent out-of-bounds indexing during the binary search.
        
        for(int i=0;i<n;i++){  //compute difference array using map
            int start=flowers[i][0];
            int end=flowers[i][1];
            mp[start]+=1;
            mp[end+1]-=1;
        }
        
        vector<int> positions;
        vector<int> prefix;
        int curr=0;
        for(auto &pair:mp){
            positions.push_back(pair.first);
            curr+=pair.second;
            prefix.push_back(curr);
        }

        vector<int> res;
        for(int person:people){
            int i=upper_bound(positions.begin(),positions.end(),person) - positions.begin() -1;
            res.push_back(prefix[i]);
        }

        return res;
    }
};