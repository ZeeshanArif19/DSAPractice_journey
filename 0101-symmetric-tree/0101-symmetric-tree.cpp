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
//if both are null then symmetric
//if only one is null then not symmetric
//if left val not equal to right val false
/*check left subtree of left node with right subtree of right node and right subtree of left node with left subtree of right node*/
class Solution {
public:
    bool dfs(TreeNode* left,TreeNode* right){
        if(left==nullptr && right==nullptr) return true;
        if((left!=NULL && right==NULL) || (left==NULL && right!=NULL)) return false;
        if(left->val!=right->val) return false;
        return dfs(left->left,right->right) && dfs(left->right,right->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        return dfs(root->left,root->right);
    }
};