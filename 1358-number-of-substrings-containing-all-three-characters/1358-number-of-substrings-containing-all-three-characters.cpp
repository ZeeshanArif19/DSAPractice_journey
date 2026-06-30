class Solution {
public:
    int numberOfSubstrings(string s) {
        int left=0;
        int right=0;
        unordered_map<char,int> count;
        int result=0;
        while(right<s.size()){
            count[s[right]]++;
            while(count['a']>0 && count['b']>0 && count['c']>0){
                result+=s.size()-right;
                count[s[left]]--;
                left++;
            }
            right++;
        }
        return result;
    }
};