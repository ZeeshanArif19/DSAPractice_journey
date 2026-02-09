/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* node,int leftpath,int rightpath,int &maxlen){
        if(node==nullptr) return;
        
        maxlen=max(maxlen,max(leftpath,rightpath));
        
        dfs(node->left,rightpath+1,0,maxlen);

        dfs(node->right,0,leftpath+1,maxlen);
    }
    int longestZigZag(TreeNode* root) {
        int maxlen=0;
        dfs(root,0,0,maxlen);
        return maxlen;
    }
};