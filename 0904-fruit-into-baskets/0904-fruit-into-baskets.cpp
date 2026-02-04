class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i=0,j=0;
        int count=0;
        unordered_map<int,int> mpp;

        while(j<fruits.size()){
            mpp[fruits[j]]++;
            while(mpp.size()>2){
                mpp[fruits[i]]--;
                if(mpp[fruits[i]]==0) mpp.erase(fruits[i]);
                i++;
            }
            if(mpp.size()<=2) count=max(count,(j-i+1));
            j++;
        }
        return count;
    }
};