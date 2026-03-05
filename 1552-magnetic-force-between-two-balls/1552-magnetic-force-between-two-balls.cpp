class Solution {
public:
    bool isValid(vector<int>& position,int force,int balls){
        int ballCnt=1;
        int lastBallPos=position[0];

        for(int i=1;i<position.size();i++){
            if(position[i]-lastBallPos>=force){
                lastBallPos=position[i];
                ballCnt++;
            }
        }
        return ballCnt>=balls;
    }
    int maxDistance(vector<int>& position, int m) {
        int n=position.size();
        sort(position.begin(),position.end());
        int l=1;
        int r=position[n-1]-position[0];
        int ans=-1;

        while(l<=r){
            int mid=l+(r-l)/2;
            if(isValid(position,mid,m)){
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        return ans;
    }
};