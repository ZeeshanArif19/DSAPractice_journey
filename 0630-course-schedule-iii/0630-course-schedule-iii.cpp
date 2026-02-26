class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int n=courses.size();
        auto cmp=[&](vector<int> &a,vector<int> &b){
            return a[1]<b[1];
        };
        sort(courses.begin(),courses.end(),cmp);

        priority_queue<int> pq;
        int total_time=0;

        for(auto &course: courses){
            int duration=course[0];
            int deadline=course[1];
            
            total_time+=duration;
            pq.push(duration);

            if(total_time>deadline){
                total_time-=pq.top();  //remove the longest course taken so far to save time
                pq.pop();
            }
        }
        return pq.size();
    }
};