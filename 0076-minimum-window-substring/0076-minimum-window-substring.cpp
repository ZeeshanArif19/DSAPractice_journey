class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mpp;
        for(char &ch:t) mpp[ch]++;
        
        int n=s.size();
        int i=0,j=0;
        int count=t.size();
        int minlen=INT_MAX;
        int startIndex=-1;

        while(j<n){
            if(mpp[s[j]]>0) count--;
            mpp[s[j]]--;
            while(count==0){
                if(minlen>j-i+1){
                    minlen=j-i+1;
                    startIndex=i;
                }
                mpp[s[i]]++;
                if(mpp[s[i]]>0) count++;
                i++;
            }
            j++;
        }
        if(startIndex==-1) return "";
        return s.substr(startIndex,minlen);
    }
};