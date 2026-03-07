class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(),stones.end());

        while(pq.size()>1){
            int lar=pq.top();
            pq.pop();
            int slar=pq.top();
            pq.pop();
            pq.push(lar-slar);
        }
        return pq.top();
    }
};