class Solution {
public:
    vector<int> primefactor(int n){
        vector<int> fac;
        while(n%2==0){
            fac.push_back(2);
            n/=2;
        }
        for(int i=3;i*i<=n;i+=2){
            while(n%i==0){
                fac.push_back(i);
                n/=i;
            }
        }
        if(n>2) fac.push_back(n);

        return fac;
    }
    int minSteps(int n) {
        vector<int> fac=primefactor(n);
        int ans=0;

        for(int &i:fac) ans+=i;

        return ans;
    }
};