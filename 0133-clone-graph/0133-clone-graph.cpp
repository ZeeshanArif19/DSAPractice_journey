/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs(Node* node,unordered_map<Node*,Node*> &mpp){
        Node* cp=new Node(node->val);
        mpp[node]=cp;
        
        for(Node* nd:node->neighbors){
            if(mpp.find(nd)==mpp.end()){
                dfs(nd,mpp);
            }
            cp->neighbors.push_back(mpp[nd]);
        }
    }
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        
        unordered_map<Node*,Node*> mpp;
        dfs(node,mpp);
        return mpp[node];
    }
};