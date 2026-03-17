class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int boatCnt=0;
        int i=0;
        int j=people.size()-1;
        
        while(i<=j){
            boatCnt++;
            if(people[i]+people[j]<=limit){
                i++;
            }
            j--;
        }
        
        return boatCnt;
    }
};