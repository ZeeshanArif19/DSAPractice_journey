class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int n=wall.size();
        unordered_map<int,int> mpp;

        for(int i=0;i<n;i++){
            for(int j=0;j<wall[i].size()-1;j++){
                if(j!=0)
                    wall[i][j]+=1LL*wall[i][j-1];

                mpp[wall[i][j]]++;
            }
        }
        
        int maxf=0;
        for(auto &it:mpp){
            if(it.second>maxf){
                maxf=it.second;
            }
        }

        return n-maxf;
    }
};