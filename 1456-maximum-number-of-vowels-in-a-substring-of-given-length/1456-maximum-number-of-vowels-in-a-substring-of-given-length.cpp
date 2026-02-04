class Solution {
public:
    int maxVowels(string s, int k) {
        int i=0;
        int j=k;
        int vowelCnt=0;

        for(int i=0;i<k;i++){
            if(s[i]=='a' ||s[i]=='e' ||s[i]=='i' ||s[i]=='o' ||s[i]=='u'){
                vowelCnt++;
            }
        }
        int maxCnt=vowelCnt;
        while(j<s.size()){
            if(s[i]=='a' ||s[i]=='e' ||s[i]=='i' ||s[i]=='o' ||s[i]=='u'){
                vowelCnt--;
            }
            if(s[j]=='a' ||s[j]=='e' ||s[j]=='i' ||s[j]=='o' ||s[j]=='u'){
                vowelCnt++;
            }
            i++;
            j++;
            maxCnt=max(maxCnt,vowelCnt);
        }
        return maxCnt;
    }
};