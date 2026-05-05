struct Node{
    Node* links[26];
    int cntEndWith=0;
    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void put(char ch,Node* node){
        links[ch-'a']=node;
    }
};
class Trie{
    private: Node* root;
    public:
    Trie(){
        root=new Node();
    }
    void insert(string &word){
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
        }
        node->cntEndWith++;
    }
    void dfs(Node* node,string &currWord,string &longestWord){
        for(int i=25;i>=0;i--){
            if(node->links[i]!=nullptr && node->links[i]->cntEndWith>0){
                currWord.push_back((char)(i+'a'));
                
                if(currWord.length()>=longestWord.length()) longestWord=currWord;
                
                dfs(node->links[i],currWord,longestWord);
                currWord.pop_back();
            }
        }
    }

    string getLongestWord(){
        string currWord="";
        string longestWord="";
        dfs(root,currWord,longestWord);
        return longestWord;
    }
};
class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie trie;
        for(string &s:words){
            trie.insert(s);
        }
        return trie.getLongestWord();
    }
};