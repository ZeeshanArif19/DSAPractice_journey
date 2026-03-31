class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        int n=values.size();
        unordered_map<int,int> useCount; //label,label count
        vector<pair<int,int>> valnum;

        for(int i=0;i<n;i++){
            valnum.push_back({values[i],labels[i]});
        }
        sort(valnum.rbegin(),valnum.rend());
        
        int sum=0;
        for(int i=0;i<n;i++){
            int val=valnum[i].first;
            int lab=valnum[i].second;
            if(numWanted>0 && useCount[lab]<useLimit){
                sum+=val;
                numWanted--;
                useCount[lab]++;
            }
        }

        return sum;
    }
};