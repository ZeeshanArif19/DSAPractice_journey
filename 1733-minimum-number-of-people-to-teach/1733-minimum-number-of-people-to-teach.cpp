class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int users=languages.size();
        vector<vector<bool>> speaks(users+1,vector<bool>(n+1,0));
        for(int i=0;i<users;i++){
            for(int &lang:languages[i]){
                speaks[i+1][lang]=1;
            }
        }

        unordered_set<int> dontKnow;
        for(int i=0;i<friendships.size();i++){
            int a=friendships[i][0];
            int b=friendships[i][1];
            bool common=false;
            for(int l=1;l<=n;l++){
                if(speaks[a][l] && speaks[b][l]){
                    common=true;
                    break;
                }
            }
            if(!common) {
                dontKnow.insert(a);
                dontKnow.insert(b);
            }
        }
        
        int minTeach=dontKnow.size();
        for(int l=1;l<=n;l++){
            int currentTeach=0;
            for(int i:dontKnow){
                if(!speaks[i][l]) currentTeach++;
            }
            minTeach=min(minTeach,currentTeach);
        }
        return minTeach;
    }
};