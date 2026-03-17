class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int i=0;
        int j=tokens.size()-1;
        int score=0;
        int currScore=0;
        while(i<=j){
            if(power>=tokens[i]){
                power-=tokens[i];
                currScore++;
                i++;
            }
            else{
                if(score>=1){
                    power+=tokens[j];
                    currScore--;
                    j--;
                }
                else break;
            }
            score=max(score,currScore);
        }
        return score;
    }
};