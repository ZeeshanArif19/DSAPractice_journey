class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double,pair<int,int>>> pq;
        int n=classes.size();
        for(int i=0;i<n;i++){
            int a=classes[i][0];
            int b=classes[i][1];
            double gain=(double)((a+1.0)/(b+1.0))-(double)a/b; 
            pq.push({gain,{a,b}});
        }
        
        for(int i=0;i<extraStudents;i++){
            int a=pq.top().second.first;
            int b=pq.top().second.second;
            pq.pop();
            a=a+1;
            b=b+1;
            double newgain=(double)(a+1.0)/(b+1.0)-(double)a/b;
            pq.push({newgain,{a,b}});
        }

        double maxratio=0;
        while(!pq.empty()){
            int a=pq.top().second.first;
            int b=pq.top().second.second;
            pq.pop();
            maxratio+=(double)a/b;
        }
        return (double)maxratio/n;  
    }
};