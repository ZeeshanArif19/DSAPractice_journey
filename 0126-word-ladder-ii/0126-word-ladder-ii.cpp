class Solution {
public:
    vector<vector<string>> res;
    void dfs(unordered_map<string,int> &mpp,string word,string beginWord,vector<string> &seq){
        if(word==beginWord){
            reverse(seq.begin(),seq.end());
            res.push_back(seq);
            reverse(seq.begin(),seq.end());
            return;
        }
        int steps=mpp[word];

        for(int i=0;i<word.size();i++){
            char orig=word[i];
            for(char ch='a';ch<='z';ch++){
                word[i]=ch;
                if(mpp.find(word)!=mpp.end() && mpp[word]+1==steps){
                    seq.push_back(word);
                    dfs(mpp,word,beginWord,seq);
                    seq.pop_back();
                }
            }
            word[i]=orig;
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(),wordList.end());
        queue<string> q;
        q.push(beginWord);
        s.erase(beginWord);
        unordered_map<string,int> mpp;
        mpp[beginWord]=1;

        while(!q.empty()){
            string word=q.front();
            q.pop();
            int steps=mpp[word];

            if(word==endWord) break;
            
            for(int i=0;i<word.size();i++){
                string orig=word;
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(s.find(word)!=s.end()){
                        q.push(word);
                        s.erase(word);
                        mpp[word]=steps+1;
                    }
                }
                word=orig;
            }
        }
        if(mpp.find(endWord)!=mpp.end()){
            vector<string> seq;
            seq.push_back(endWord);
            dfs(mpp,endWord,beginWord,seq);
        }
        return res;
    }
};