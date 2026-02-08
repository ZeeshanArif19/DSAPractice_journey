class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n=nums.size();
        int maxlen=0;
        deque<int> maxD,minD;
        int i=0;

        for(int j=0;j<n;j++){
            while(!maxD.empty() && nums[maxD.back()]<=nums[j]){
                maxD.pop_back();
            }
            maxD.push_back(j);
            while(!minD.empty() && nums[minD.back()]>=nums[j]){
                minD.pop_back();
            }
            minD.push_back(j);

            while(i<=j){
                int currMax=nums[maxD.front()];
                int currMin=nums[minD.front()];
                int len=j-i+1;

                if(abs(currMax-currMin)>limit){
                    i++;
                    if(!maxD.empty() && maxD.front()<i) maxD.pop_front();
                    if(!minD.empty() && minD.front()<i) minD.pop_front();
                }
                else break;
            }
            maxlen=max(maxlen,(j-i+1));
        }
        return maxlen;
    }
};