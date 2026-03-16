class Solution {
public:
    bool isValid(vector<int>& grades,int mid){
        int groupCnt=0;
        int sum=0;
        for(int i=1;i<=mid;i++){
            sum+=i;
        }
        return sum<=grades.size();
    }
    int maximumGroups(vector<int>& grades) {
        int l=1;
        int r=grades.size();
        int ans=-1;

        while(l<=r){
            int mid=l+(r-l)/2;
            if(isValid(grades,mid)){
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        return ans;
    }
};