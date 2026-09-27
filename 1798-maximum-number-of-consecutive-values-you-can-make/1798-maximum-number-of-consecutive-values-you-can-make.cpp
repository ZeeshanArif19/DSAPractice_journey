class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        sort(coins.begin(),coins.end());
        int currsum=0;
        //, if the next coin we get is greater than the maximum sequence currently formed, we cannot extend the sequence in any case whatsoever.
        for(int &coin:coins){
            if(coin<=currsum+1) currsum+=coin;
            else break;
        }
        return currsum+1;
    }
};