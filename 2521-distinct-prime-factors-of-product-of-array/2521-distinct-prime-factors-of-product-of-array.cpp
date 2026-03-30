class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> primefactors;

        for(int &i:nums){
            int temp=i;
            for(int j=2;j*j<=temp;j++){
                if(temp%j==0) primefactors.insert(j);

                while(temp%j==0){ //to ensure we get distinct prime factors
                    temp/=j;
                }
            }
            if(temp>1) primefactors.insert(temp);
        }
        return primefactors.size();
    }
};