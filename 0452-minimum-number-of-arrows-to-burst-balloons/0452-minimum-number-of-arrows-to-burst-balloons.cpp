class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size();
        auto cmp=[&](vector<int> &a,vector<int> &b){
            return a[1]<b[1];
        };
        sort(points.begin(),points.end(),cmp);

        int arrowCnt=1;
        int last_shoot=points[0][1];

        for(int i=1;i<n;i++){
            if(last_shoot>=points[i][0] && last_shoot<=points[i][1]){
                continue;
            }
            else{
                last_shoot=points[i][1];
                arrowCnt++;
            }
        }
        return arrowCnt;
    }
};