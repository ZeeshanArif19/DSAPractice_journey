class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n=profit.size();
        vector<pair<int,int>> job(n);
        for(int i=0;i<n;i++){
            job[i]={difficulty[i],profit[i]};
        }
        sort(job.begin(),job.end());
        
        sort(worker.begin(),worker.end());
        int m=worker.size();
        int i=0;
        int j=0;
        int maxProfit=0;
        int currmax=0;
        while(i<m){
            while(j<n && job[j].first<=worker[i]){
                currmax=max(currmax,job[j].second);
                j++;
            }
            maxProfit+=currmax;
            i++;
        }
        return maxProfit;
    }
};