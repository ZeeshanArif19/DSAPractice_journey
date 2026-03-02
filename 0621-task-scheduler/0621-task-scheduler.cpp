class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int total_tasks=tasks.size();
        int maxf=0;
        vector<int> freq(26,0);

        for(char &it:tasks){
            freq[it-'A']++;
            maxf=max(maxf,freq[it-'A']);
        }

        int count_maxf=0;
        for(int &it:freq){
            if(it==maxf) count_maxf++;
        }

        int idle=(maxf-1)*(n+1)+count_maxf;

        return max(total_tasks,idle); //max(idle,busy)
    }
};