class Solution {
public:
    bool isValid(vector<int>& price,int k,int maxtasty){
        int candyCnt=1;
        int lastCandyPos=price[0];
        
        for(int i=0;i<price.size();i++){
            if(price[i]-lastCandyPos>=maxtasty){
                candyCnt++;
                lastCandyPos=price[i];
            }
        }
        return candyCnt>=k;
    }
    int maximumTastiness(vector<int>& price, int k) {
        int n=price.size();
        sort(price.begin(),price.end());
        int l=0;
        int r=price[n-1]-price[0];
        int ans=-1;

        while(l<=r){
            int mid=l+(r-l)/2;
            if(isValid(price,k,mid)){
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        return ans;
    }
};