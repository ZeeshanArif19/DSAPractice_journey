class Solution {
public:
    int sumarr(vector<int> &weights,int n){
        int sum=0;
        for(int i=0;i<n;i++) sum+=weights[i];
        return sum;
    }
    bool isValid(vector<int> &weights,int maxweight,int maxdays,int n){
        int sumweights=0;
        int days=1;
        for(int i=0;i<n;i++){
            if(weights[i]>maxweight) return false;
            if(weights[i]+sumweights<=maxweight){
                sumweights+=weights[i];
            }
            else{
                days++;
                sumweights=weights[i];
            }
        }
        return days<=maxdays;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int l=1;
        int r=sumarr(weights,n);
        int ans=-1;

        while(l<=r){
            int mid=l+(r-l)/2;
            if(isValid(weights,mid,days,n)){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};