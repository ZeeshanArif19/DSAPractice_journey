class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n=grid.size();
        int totalsum=0;
        vector<int> horizMax(n);
        vector<int> vertiMax(n);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                horizMax[i]=max(grid[i][j],horizMax[i]);
                vertiMax[j]=max(grid[i][j],vertiMax[j]);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                totalsum+=(min(horizMax[i],vertiMax[j])-grid[i][j]);
            }
        }
        return totalsum;
    }
};