class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq(piles.begin(),piles.end());
        int minStonesleft=0;
        
        while(!pq.empty() && k>0){
            int top=pq.top();
            pq.pop();
            pq.push(top-floor((double)top/2));
            k--;
        }

        while(!pq.empty()){
            int top=pq.top();
            pq.pop();
            minStonesleft+=top;
        }
        return minStonesleft;
    }
};