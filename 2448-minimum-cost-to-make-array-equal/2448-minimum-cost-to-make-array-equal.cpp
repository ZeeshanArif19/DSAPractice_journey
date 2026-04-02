class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n=nums.size();
        vector<pair<long long,long long>> numcost(n);
        for(int i=0;i<n;i++){
            numcost[i]={nums[i],cost[i]};
        }
        sort(numcost.begin(),numcost.end());

        long long sumcost=accumulate(cost.begin(),cost.end(),0LL); //find weighted median
        long long median=0;
        long long runningcost=0;
        for(int i=0;i<n;i++){
            runningcost+=numcost[i].second;
            if(runningcost>=(sumcost+1)/2) {
                median=numcost[i].first;
                break;
            }
        }

        long long totalcost=0;
        for(int i=0;i<n;i++){
            long long delcount=abs(numcost[i].first-median);
            totalcost+=(delcount*numcost[i].second);
        }
        return totalcost;
    }
};