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
    pair<int,int> dfs(TreeNode* node){
        if(node==NULL) return {0,0};
        
        pair<int,int> left=dfs(node->left);
        pair<int,int> right=dfs(node->right);
        
        int maxinclude=left.second + right.second + node->val;
        int maxexclude=max(left.first,left.second) + max(right.first,right.second);
        
        return {maxinclude,maxexclude};
    }
    int rob(TreeNode* root) {
        pair<int,int> ans=dfs(root);
        int maxamount=max(ans.first,ans.second);
        return maxamount;
    }
};