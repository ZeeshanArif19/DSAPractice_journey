class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        vector<pair<int,int>> number; //num2,num1
        for(int i=0;i<n;i++){
            number.push_back({nums2[i],nums1[i]});
        }
        sort(number.begin(),number.end(),greater<pair<int,int>>()); //sort in DESC based on nums2

        priority_queue<int,vector<int>,greater<int>> pq;
        //store nums1, minheap because if size exceed we have to remove the minimum num to make sure that our score is maximum 

        long long maxScore=0;
        long long sumElem=0;

        for(auto &num:number){
            int num2=num.first;
            int num1=num.second;
            
            pq.push(num1);
            sumElem+=num1;

            while(pq.size()>k){
                sumElem-=pq.top();
                pq.pop();
            }
            if(pq.size()==k){
                maxScore=max(maxScore,sumElem*num2);
            }
        }
        return maxScore;
    }
};