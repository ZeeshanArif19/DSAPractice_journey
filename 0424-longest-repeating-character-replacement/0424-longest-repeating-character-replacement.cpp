class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int hash[26]={0};
        int i=0,j=0;
        int maxf=0,maxlen=0;

        while(j<n){
            hash[s[j]-'A']++;
            maxf=max(maxf,hash[s[j]-'A']);

            if((j-i+1)-maxf<=k){
                maxlen=max(maxlen,(j-i+1));
            }
            else{
                hash[s[i]-'A']--;
                i++;
            }
            j++;
        }
        return maxlen;
    }
};