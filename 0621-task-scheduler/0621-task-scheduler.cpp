class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int total_tasks=tasks.size();
        int maxf=0;
        int count_maxf=0;
        vector<int> freq(26,0);

        // for(char &it:tasks){
        //     freq[it-'A']++;
        //     maxf=max(maxf,freq[it-'A']);
        // }
        // for(int &it:freq){
        //     if(it==maxf) count_maxf++;
        // }
        //one pass soln
        for(char &it:tasks){
            freq[it-'A']++;
            if(freq[it-'A']>maxf){
                maxf=freq[it-'A'];
                count_maxf=1;
            }
            else if(maxf==freq[it-'A']){
                count_maxf++;
            }
        }
        int idle=(maxf-1)*(n+1)+count_maxf;

        return max(total_tasks,idle); //max(idle,busy)

    }
};