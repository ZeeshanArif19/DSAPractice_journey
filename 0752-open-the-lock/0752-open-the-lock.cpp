class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> s;
        for(string deadend:deadends) s.insert(deadend);
        if(s.find("0000")!=s.end()) return -1;

        queue<pair<string,int>> q;
        int steps=0;
        q.push({"0000",steps});

        while(!q.empty()){
            string combination=q.front().first;
            steps=q.front().second;
            q.pop();
            
            if(combination==target) return steps;

            for(int i=0;i<4;i++){
                char origchar=combination[i];
                char nextchar=(origchar=='9')?'0':origchar+1;
                char prevchar=(origchar=='0')?'9':origchar-1;
                string moves[]={combination,combination};
                moves[0][i]=nextchar;
                moves[1][i]=prevchar;

                for(string &i:moves){
                    if(s.find(i)==s.end()){   //we cannot find --> safe
                        s.insert(i);
                        q.push({i,steps+1});
                    }
                }
            }
        }
        return -1;
    }
};