class Solution {
public:
    int longestSubstring(string s, int k) {
        int n=s.size();
        if(n<k) return 0; //base case 1: if string is shorter than k its impossible

        unordered_map<int,int> mpp;
        for(char &c:s) mpp[c]++; //count freq
        
        for(int i=0;i<n;i++){  //find the bad char
            if(mpp[s[i]]<k){
                string leftString=s.substr(0,i);
                
                int nextvalid=i+1;
                while(nextvalid<n && mpp[s[nextvalid]]<k){  //optimization skip any consecutive bad chars
                    nextvalid++;
                }
                string rightString=s.substr(nextvalid);
                //return maxlen found in either half
                return max(longestSubstring(leftString,k), longestSubstring(rightString,k));
            }
        }
        return n; //if we made through the loop the entire string is valid
    }
};