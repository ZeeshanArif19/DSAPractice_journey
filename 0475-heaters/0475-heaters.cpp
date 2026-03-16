class Solution {
public:
    bool isValid(vector<int>& houses,vector<int>& heaters,int radius){
        int j=0;
        int i=0;
        while(i<houses.size() && j<heaters.size()){
            if(abs(houses[i]-heaters[j])<=radius){
                i++;
            }
            else if(houses[i]<heaters[j]-radius){
                return false;
            }
            else j++;
        }
        return i==houses.size();
    }
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        int l=0;
        int r=max(houses.back(),heaters.back())-min(houses.front(),heaters.front());
        int ans=-1;

        while(l<=r){
            int mid=l+(r-l)/2;
            if(isValid(houses,heaters,mid)){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};