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
    TreeNode* findMin(TreeNode* node){
        while(node->left!=NULL){
            node=node->left;
        }
        return node;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return nullptr;
        if(key>root->val){
            root->right=deleteNode(root->right,key);
        }
        else if(key<root->val){
            root->left=deleteNode(root->left,key);
        }
        else{
            if(!root->left && !root->right){
                return nullptr;
            }
            else if(!root->left && root->right){
                return root->right;
            }
            else if(root->left && !root->right){
                return root->left;
            }
            else{
                TreeNode* successor=findMin(root->right);
                root->val=successor->val;
                root->right=deleteNode(root->right,successor->val);
            }
        }
        return root;
    }
};