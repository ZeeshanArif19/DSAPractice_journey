class Solution {
public:
    long long ncr(int n,int r){
        if(r>n) return 0;
        
        r=min(r,n-r);

        long long res=1;
        for(int i=1;i<=r;i++){
            res=res* (n-r+i)/i;
        }

        return res;
    }
    int numTrees(int n) {
        long long ans=ncr(2*n,n)/(n+1);
        return ans;
    }
};