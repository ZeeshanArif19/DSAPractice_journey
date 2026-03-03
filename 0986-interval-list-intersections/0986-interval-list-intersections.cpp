class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int i=0,j=0;
        int n=firstList.size();
        int m=secondList.size();
        vector<vector<int>> res;
        
        while(i<n && j<m){
            int first=max(firstList[i][0],secondList[j][0]);
            int second=min(firstList[i][1],secondList[j][1]);
            
            if(first<=second){
                res.push_back({first,second});
            }

            if(firstList[i][1]<=secondList[j][1]) i++;
            else j++;
        }
        return res;
    }
};