class Solution {
public:
    int MAX=1e9+7;
    vector<bool> seive(int n){
        vector<bool> prime(n+1,true);
        prime[0]=prime[1]=false;
        for(int p=2;p*p<=n;p++){
            if(prime[p]==true){
                for(int i=p*p;i<=n;i+=p) prime[i]=false;
            }
        }

        return prime;
    }
    long long factorial(int n){
        long long ans=1;
        for(int i=2;i<=n;i++){
            ans=(ans*i)%MAX;
        }
        return ans;
    }
    int numPrimeArrangements(int n) {
        vector<bool> prime=seive(n);
        int primeCnt=0;
        for(int i=2;i<=n;i++){
            if(prime[i]==true) primeCnt++;
        }
        int notPrimeCnt=n-primeCnt;

        return (factorial(primeCnt)*factorial(notPrimeCnt))%MAX;
    }
};