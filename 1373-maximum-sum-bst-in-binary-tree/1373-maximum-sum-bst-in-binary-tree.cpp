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
    int maxsum=0;

    struct SubTreeInfo{
        bool isBst;
        int minval;
        int maxval;
        int sum;
    };
    SubTreeInfo traverse(TreeNode* node){
        if(node==nullptr) return {true,INT_MAX,INT_MIN,0};

        SubTreeInfo left=traverse(node->left);
        SubTreeInfo right=traverse(node->right);

        if(left.isBst && right.isBst && node->val>left.maxval && node->val<right.minval){

            int currentsum= node->val+left.sum+right.sum;
            maxsum=max(maxsum,currentsum);

            return {
                true,
                min(node->val,left.minval),
                max(node->val,right.maxval),
                currentsum
            };
        }
        return {false,0,0,0};
    }

    int maxSumBST(TreeNode* root) {
        maxsum=0;
        traverse(root);
        return maxsum;
    }
};