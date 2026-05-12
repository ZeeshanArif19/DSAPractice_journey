class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diffArr(n,0);
        //standard difference array problem
        for(auto &it:bookings){ //compute difference array
            int i=it[0];
            int j=it[1];
            int k=it[2];
            
            diffArr[i-1]+=k;
            if(j<n) diffArr[j]-=k;
        }
        //compute prefix sum of diff arr to get the answer
        vector<int> res(n,0);
        int val=0;
        for(int i=0;i<n;i++){
            val+=diffArr[i];
            res[i]=val;
        }
        return res;
    }
};