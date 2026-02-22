class Solution {
public:
    int kIncreasing(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> temp;
        int total_ops=0;

        for(int i=0;i<k;i++){
            temp.clear();
            for(int j=i;j<n;j+=k){
                int val=arr[j];
                
                if(temp.empty() || val>=temp.back()){
                    temp.emplace_back(val);
                    total_ops++;
                }
                else{
                    int ind=upper_bound(temp.begin(),temp.end(),val)-temp.begin();
                    temp[ind]=val;
                }
            }
        }
        return n-total_ops;
    }
};