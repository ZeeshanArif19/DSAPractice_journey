class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> res;
        int start=0;
        int end=0;
        vector<int> lastInd(26);
        for(int i=0;i<s.size();i++){
            lastInd[s[i]-'a']=i;
        }

        // while(start<s.size()){
        //     end=lastInd[s[start]-'a'];
        //     for(int i=start;i<=end;i++){
        //         if(lastInd[s[i]-'a']>end){
        //             end=lastInd[s[i]-'a'];
        //         }
        //     }

        //     res.push_back(end-start+1);
        //     start=end+1;
        // }
        for(int i=0;i<s.size();i++){
            end=max(end,lastInd[s[i]-'a']);
            if(i==end){
                res.push_back(end-start+1);
                start=end+1;
            }
        }
        return res;
    }
};