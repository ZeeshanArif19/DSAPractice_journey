class Solution {
public:
    bool isValid(vector<int>& dist,double hour,int speed){
        double totTime=0;
        // All legs except the last must finish on an integer hour (wait for the next train).
        // The last leg doesn't have a next train, so we take the exact decimal time.
        for(int i=0;i<dist.size();i++){
            double currTime=(double)dist[i]/speed;
            if(i==dist.size()-1){
                totTime+=currTime;
            }
            else{
                totTime+=ceil(currTime);
            }
        }
        return totTime<=hour;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int l=1;
        int r=1e9;
        int ans=-1;

        while(l<=r){
            int mid=l+(r-l)/2;
            if(isValid(dist,hour,mid)){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};