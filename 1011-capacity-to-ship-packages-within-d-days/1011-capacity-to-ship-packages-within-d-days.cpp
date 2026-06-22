class Solution {
public:
    bool isValid(int cap,int days,vector<int> &weights){
        int count=1;
        int w=0;

        for(int i=0;i<weights.size();i++){
            if(weights[i]>cap) return false;
            else if(weights[i]+w<=cap){
                w+=weights[i];
            }
            else{
                count++;
                w=weights[i];
            }
        }
        return count<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int l=1;
        int r=accumulate(weights.begin(),weights.end(),0);
        int ans=-1;

        while(l<=r){
            int mid=l+(r-l)/2;
            if(isValid(mid,days,weights)){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};