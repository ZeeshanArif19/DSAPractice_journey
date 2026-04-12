class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size();
        int cnt=0;
        int maxlen=0;
        int left=-1;

        for(int i=0;i<n;i++){
            if(cnt<0){  //If balance becomes negative, it means there are more ) than ( and the substring cannot be valid anymore. So we reset the starting boundary.
                left=i-1;
                cnt=0;
            }
            if(s[i]=='(') cnt++;
            else cnt--;
            
            if(cnt==0){ //balanced
                maxlen=max(maxlen,i-left);
            }
        }
        
        //a single left to right scan fails for cases like (()
        //to handle extra ( cases we perform a second scan from right to left
        int right=n;
        cnt=0;
        for(int i=n-1;i>=0;i--){
            if(cnt<0){
                right=i+1;
                cnt=0;
            }
            if(s[i]==')') cnt++;
            else cnt--;

            if(cnt==0){
                maxlen=max(maxlen,right-i);
            }
        }
        return maxlen;
    }
};