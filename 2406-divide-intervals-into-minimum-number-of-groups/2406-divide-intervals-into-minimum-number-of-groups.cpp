class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<int> diffArr(1e6+1,0);
        
        int maxInd=-1;
        for(int i=0;i<intervals.size();i++){
            int l=intervals[i][0];
            int r=intervals[i][1];
            maxInd=max(r,maxInd);

            diffArr[l-1]+=1;
            diffArr[r]-=1;
        }
        
        int overlaps=0;
        int maxGrps=0;
        for(int i=0;i<maxInd;i++){
            overlaps+=diffArr[i];
            diffArr[i]=overlaps;
            maxGrps=max(maxGrps,diffArr[i]);
        }
        return maxGrps;
    }
};