class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        vector<char> choices={'A','C','G','T'};
        unordered_set<string> s;
        for(string gene:bank){
            s.insert(gene);
        }
        queue<pair<string,int>> q;
        int steps=0;
        q.push({startGene,steps});
        
        while(!q.empty()){
            string gene=q.front().first;
            steps=q.front().second;
            q.pop();
            
            if(gene==endGene) return steps;

            for(int i=0;i<8;i++){
                string temp=gene;
                for(int j=0;j<4;j++){
                    gene[i]=choices[j];
                    if(s.find(gene)!=s.end()){
                        q.push({gene,steps+1});
                        s.erase(gene);
                    }
                }
                gene=temp;  //restore
            }
        }
        return -1;
    }
};