class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int i=0;
        int j=0;
        int count=0;
        int maxlen=0;
        vector<int> hash(256,0);
        while(j<n){
            if(hash[s[j]]==0){
                hash[s[j]]++;
                count++;
                j++;
            }
            else{
                hash[s[i]]--;
                count--;
                i++;
            }
            maxlen=max(maxlen,count);
        }
        return maxlen;
    }
};
