class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int q=shifts.size();
        int n=s.size();
        //difference array
        vector<int> diffArr(n+1,0);
        for(int i=0;i<q;i++){
            int start=shifts[i][0];
            int end=shifts[i][1];
            int direction=(shifts[i][2]==1) ? 1 : -1;

            diffArr[start]+=direction;
            diffArr[end+1]-=direction;
        }
        //prefix sum of diffArr
        string res="";
        int prefix=0;
        for(int i=0;i<n;i++){
            diffArr[i]+=prefix;
            prefix=diffArr[i]; 

            int safe_shift=(diffArr[i] % 26 +26) % 26;
            char ch=((s[i]-'a'+safe_shift) % 26)+97; //caesar cipher formula
            res.push_back(ch);
        }
        return res;
    }
};