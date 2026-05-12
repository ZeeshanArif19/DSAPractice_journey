class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> diffArr(1000,0);
        int maxInd=-1;
        //difference array
        for(int k=0;k<trips.size();k++){
            int i=trips[k][1];
            int j=trips[k][2];
            int pasn=trips[k][0];
            maxInd=max(maxInd,j);

            diffArr[i]+=pasn;
            if(j<1000) diffArr[j]-=pasn;
        }

        //prefix sum
        int passCnt=0;
        for(int i=0;i<maxInd;i++){
            passCnt+=diffArr[i];
            diffArr[i]=passCnt;
            if(diffArr[i]>capacity) return false;
        }
        return true;
    }
};