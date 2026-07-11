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
    int solve(TreeNode* node,int max_so_far){
        if(node==NULL) return 0;

        int next_max=max(max_so_far,node->val);
        int left=solve(node->left,next_max);
        int right=solve(node->right,next_max);

        int isgood=(node->val>=max_so_far)? 1 : 0;
        return isgood+left+right;
    }
    int goodNodes(TreeNode* root) {
        int max_so_far=root->val;
        return solve(root,max_so_far);
    }
};