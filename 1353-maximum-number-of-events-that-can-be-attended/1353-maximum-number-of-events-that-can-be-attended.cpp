class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n=events.size();
        sort(events.begin(),events.end());
        
        priority_queue<int,vector<int>,greater<int>> pq;  //store the end day
        int i=0,count=0,current_day=0;

        while(i<n || !pq.empty()){
            if(pq.empty()) current_day=events[i][0];

            while(i<n && events[i][0]==current_day){
                pq.push(events[i][1]);
                i++;
            }
            // check expiration
            while(!pq.empty() && pq.top()<current_day){
                pq.pop();
            }
            //greedily attend the event
            if(!pq.empty()){
                pq.pop();
                count++;
                current_day++;
            }
        }
        return count;
    }
};