class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int n=arr.size();
        long long MOD=1e9 +7;
        long long totalsum=0;
        for(int &i: arr) totalsum+=i;
        
        auto kadane=[&](int k){
            long long currsum=0;
            long long maxsum=0;
            for(int i=0;i<n*k;i++){
                currsum=max((long long)arr[i%n],currsum+arr[i%n]);
                maxsum=max(maxsum,currsum);
            }
            return maxsum;
        };
        
        if(k==1){
            return kadane(1) %MOD;
        }
        else if(totalsum>0){
            return (kadane(2) + (k-2) * totalsum)%MOD;
        }
        else{
            return kadane(2)%MOD;
        }
    } 
};