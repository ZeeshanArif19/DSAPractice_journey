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
    bool sameTree(TreeNode* node, TreeNode* subRoot){
        if(node==NULL && subRoot==NULL) return true;
        if((node==NULL && subRoot!=NULL) || (node!=NULL && subRoot==NULL)) return false;
        if(node->val!=subRoot->val) return false;
        
        return sameTree(node->left,subRoot->left) && sameTree(node->right,subRoot->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL) return false;

        if(sameTree(root,subRoot)){
            return true;
        }

        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
};