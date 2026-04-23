class Node{
    public:
    Node* children[26];
    bool isEnd;
    Node(){
        isEnd=false;
        for(int i=0;i<26;i++){
            children[i]=nullptr;
        }
    }
};
class WordDictionary {
public:
    Node* root;
    WordDictionary() {
        root=new Node();
    }
    
    void addWord(string word) {
        Node* curr=root;
        for(char c:word){
            if(curr->children[c-'a']==nullptr){
                curr->children[c-'a']=new Node();
            }
            curr=curr->children[c-'a'];
        }
        curr->isEnd=true;
    }
    
    bool search(string word) {
        return searchHelper(word,0,root);
    }

    private:
    bool searchHelper(string &word,int index,Node* curr){
        if(index==word.size()){
            return curr->isEnd;
        }
        char c=word[index];
        
        if(c=='.'){
            for(int i=0;i<26;i++){
                if(curr->children[i]!=nullptr){
                    if(searchHelper(word,index+1,curr->children[i]))
                        return true;
                }
            }
            return false;
        }
        else{
            int childIndex=c-'a';
            if(curr->children[childIndex]==nullptr) return false;
            curr=curr->children[childIndex];
            return searchHelper(word,index+1,curr);
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */