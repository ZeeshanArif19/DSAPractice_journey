class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n=spells.size();
        int m=potions.size();
        int i=0,j=0;
        vector<int> res(n);
        sort(potions.begin(),potions.end());
        
        while(i<n){
            int left=0;
            int right=m-1;
            int first_valid=m;

            while(left<=right){
                int mid=left+(right-left)/2;
                long long pro=spells[i]*1LL*potions[mid];
                if(pro>=success){
                    first_valid=mid;
                    right=mid-1;
                }
                else{
                    left=mid+1;
                }
            }
            res[i]=m-first_valid;
            i++;
        }
        return res;
    }
};