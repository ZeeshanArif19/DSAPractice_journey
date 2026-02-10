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
    int heightTree(TreeNode* node){
        int height=0;
        while(node!=nullptr){
            height++;
            node=node->left;
        }
        return height;
    }
    int countNodes(TreeNode* root) {
        if(root==nullptr) return 0;

        int height=heightTree(root);
        
        if(heightTree(root->right)==height-1){   //left subtree is complete
            return (1<<(height-1)) + countNodes(root->right);
        }
        else{               //right subtree is complete but small
            return (1<<(height-2)) + countNodes(root->left);
        }
    }
};