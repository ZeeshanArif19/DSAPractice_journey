class Solution {
public:
    int smallestValue(int n) {
        int prev=n;
        bool flag=0;
        while(true){
            if(prev==n && flag==1) return n;
            prev=n;
            flag=1;
            int sumOfPrime=0;
            for(int j=2;j*j<=n;j++){
                while(n%j==0){
                    sumOfPrime+=j;
                    n/=j;
                }
            }
            if(n>1) sumOfPrime+=n;
            n=sumOfPrime;
        }

        return n;
    }
};