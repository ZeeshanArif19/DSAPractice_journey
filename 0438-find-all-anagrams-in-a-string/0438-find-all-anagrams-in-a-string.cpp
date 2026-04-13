class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n1=s.size();
        unordered_map<char,int> mpp;
        vector<int> ans;
        for(char &i:p) mpp[i]++;

        int left=0,right=0;
        int k=p.size();
        int count=mpp.size();
        
        while(right<n1){
            if(mpp.find(s[right])!=mpp.end()){
                mpp[s[right]]--;
                if(mpp[s[right]]==0) count--;
            }
            
            if(right-left+1==k){
                if(count==0) ans.push_back(left);
                
                if(mpp.find(s[left])!=mpp.end()){
                    if(mpp[s[left]]==0){
                        count++;
                    }
                    mpp[s[left]]++;
                }
                left++;
            }
            right++;
        }
        return ans;
    }
};