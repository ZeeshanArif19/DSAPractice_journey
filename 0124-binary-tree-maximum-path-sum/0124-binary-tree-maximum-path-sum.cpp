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
    int dfs(TreeNode* node,int &maxsum){
        if(node==nullptr) return 0;
        
        int leftsum=max(0,dfs(node->left,maxsum));
        int rightsum=max(0,dfs(node->right,maxsum));

        int sum=leftsum+rightsum+node->val;
        maxsum=max(sum,maxsum);
        return node->val+max(leftsum,rightsum);
    }
    int maxPathSum(TreeNode* root) {
        int maxsum=INT_MIN;
        dfs(root,maxsum);
        return maxsum;
    }
};