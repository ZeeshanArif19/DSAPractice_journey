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
    int dfs(TreeNode* root,int &totalmoves){
        if(root==NULL) return 0;
        
        int left=dfs(root->left,totalmoves);
        int right=dfs(root->right,totalmoves);

        totalmoves+=abs(left)+abs(right);
        return (root->val + left + right - 1); 
    }

    int distributeCoins(TreeNode* root) {
       int totalmoves=0;
       dfs(root,totalmoves);
       return totalmoves;
    }
};