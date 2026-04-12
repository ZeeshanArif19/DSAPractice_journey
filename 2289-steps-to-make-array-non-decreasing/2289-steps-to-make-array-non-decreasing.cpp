class Solution {
public:
    int totalSteps(vector<int>& nums) {
        int n=nums.size();
        vector<int> maxSteps(n,0);
        stack<int> st;
        int steps=0;

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[i]>nums[st.top()]){
                maxSteps[i]=max(maxSteps[i]+1,maxSteps[st.top()]);
                st.pop();
            }
            st.push(i);
            steps=max(steps,maxSteps[i]); 
        }
        return steps;
    }
};