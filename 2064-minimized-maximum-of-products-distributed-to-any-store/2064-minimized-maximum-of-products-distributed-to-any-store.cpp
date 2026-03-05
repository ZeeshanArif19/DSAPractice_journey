class Solution {
public:
    bool isValid(vector<int> &quantities,int shops,int give){
        int shopCnt=0;
        
        for(int i=0;i<quantities.size();i++){
            shopCnt+=ceil((double)quantities[i]/give);
        }
        return shopCnt<=shops;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int l=1;
        int r=*max_element(quantities.begin(),quantities.end());
        int ans=-1;

        while(l<=r){
            int mid=l+(r-l)/2;
            if(isValid(quantities,n,mid)){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};