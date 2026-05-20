class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> s;
        for(string deadend:deadends){
            s.insert(deadend);
        }
        if(s.find("0000")!=s.end()) return -1;

        int steps=0;
        queue<pair<string,int>> q;
        q.push({"0000",steps});
        
        while(!q.empty()){
            string combo=q.front().first;
            steps=q.front().second;
            q.pop();
            
            if(combo==target) return steps;

            for(int i=0;i<4;i++){
                char origch=combo[i];
                char nextch=(origch=='9')?'0':origch+1;
                char prevch=(origch=='0')?'9':origch-1;
                string moves[]={combo,combo};
                moves[0][i]=nextch;
                moves[1][i]=prevch;

                for(string move:moves){
                    if(s.find(move)==s.end()){
                        s.insert(move);
                        q.push({move,steps+1});
                    }
                }
            }
        }
        return -1;
    }
};