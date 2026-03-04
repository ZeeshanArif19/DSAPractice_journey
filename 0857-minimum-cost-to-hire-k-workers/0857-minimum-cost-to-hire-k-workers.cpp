class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n=quality.size();
        vector<pair<double,int>> workers;
        for(int i=0;i<n;i++){
            workers.push_back({(double)wage[i]/quality[i],quality[i]}); //quality ratio,quality
        }
        sort(workers.begin(),workers.end());

        priority_queue<int> pq;  //to store quality
        double sumQuality=0;
        double leastMoney=DBL_MAX;
        
        for(auto &w:workers){
            double qr=w.first;
            int ql=w.second;

            pq.push(ql);
            sumQuality+=ql;

            while(pq.size()>k){
                sumQuality-=pq.top();
                pq.pop();
            }

            if(pq.size()==k){
                leastMoney=min(leastMoney,sumQuality*qr);
            }
        }
        return leastMoney;
    }
};