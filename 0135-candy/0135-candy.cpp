class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        int candyCnt=0;
        vector<int> candies(n,1);
        
        for(int i=1;i<n;i++){  //check left child
            if(ratings[i]>ratings[i-1]){
                candies[i]=candies[i-1]+1;
            }
        }
        
        for(int i=n-2;i>=0;i--){  //check right child
            if(ratings[i]>ratings[i+1]){
                candies[i]=max(candies[i],candies[i+1]+1);
            }
        }

        for(int i=0;i<n;i++) candyCnt+=candies[i];

        return candyCnt;
    }
};