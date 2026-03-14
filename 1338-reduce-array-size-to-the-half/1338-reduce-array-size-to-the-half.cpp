class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int> mpp; //num,freq
        for(int &i:arr) mpp[i]++;

        priority_queue<int> pq;
        for(auto &it:mpp){
            pq.push(it.second);
        }
        
        int minRemoval=0;
        while(!pq.empty()){
            if(n<=arr.size()/2) break;
            n-=pq.top();
            minRemoval++;
            pq.pop();
        }
        return minRemoval;
    }
};