class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n=beginWord.size();
        //store in hashset for o(1) lookups
        unordered_set<string> s;
        for(string word:wordList){
            s.insert(word);
        }
        if(s.find(endWord)==s.end()) return 0; //chech if endword exists at all

        queue<pair<string,int>> q;
        int seqCount=1;
        q.push({beginWord,seqCount});  //word,seqCount
        
        while(!q.empty()){
            string word=q.front().first;
            seqCount=q.front().second;
            q.pop();

            if(word==endWord) return seqCount;
            for(int i=0;i<n;i++){
                string temp=word;
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(s.find(word)!=s.end()){
                        q.push({word,seqCount+1});
                        s.erase(word);
                    }
                }
                word=temp;  //restore the word
            }
        }
        return 0;
    }
};