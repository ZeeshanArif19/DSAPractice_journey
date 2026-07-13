class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n=words.size();
        vector<pair<int,int>> masks(n); //mask,size
        
        for(int i=0;i<n;i++){  //precompute the masks and size of each string
            string s=words[i];
            int mask=0;
            for(int j=0;j<s.size();j++){
                char ch=s[j];
                mask|=(1<<ch-'a');
            }
            masks[i]={mask,s.size()};
        }

        int maxpro=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){ //compare every string
                if((masks[i].first & masks[j].first)==0){ //if no common letter AND will return 0
                    maxpro=max(maxpro,masks[i].second*masks[j].second);
                }
            }
        }

        return maxpro;
    }
};