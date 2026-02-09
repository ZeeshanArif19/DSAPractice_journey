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
    int dfs(TreeNode* node,int &maxlen){
        if(node==nullptr) return 0;

        int left=dfs(node->left,maxlen);
        int right=dfs(node->right,maxlen);

        int leftpath=0,rightpath=0;
        if(node->left!=nullptr && node->val==node->left->val){
            leftpath=left+1;
        }
        if(node->right!=nullptr && node->val==node->right->val){
            rightpath=right+1;
        } 
        maxlen=max(maxlen,leftpath+rightpath);
        return max(leftpath,rightpath);
    }
    int longestUnivaluePath(TreeNode* root) {
        int maxlen=0;
        dfs(root,maxlen);
        return maxlen;
    }
};