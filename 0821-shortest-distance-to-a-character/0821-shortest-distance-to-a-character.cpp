class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n=s.size();
        vector<int> dist(n,INT_MAX);
        
        int target_index=-1;
        for(int i=0;i<n;i++){
            if(s[i]==c){
                target_index=i;
            }
            if(target_index!=-1) dist[i]=i-target_index;
        }

        target_index=-1;
        for(int i=n-1;i>=0;i--){
            if(s[i]==c) target_index=i;
            if(target_index!=-1) dist[i]=min(dist[i],target_index-i);
        }
        return dist;
    }
};