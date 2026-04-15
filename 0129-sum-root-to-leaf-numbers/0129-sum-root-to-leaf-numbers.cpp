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
    void dfs(TreeNode* node,int &sum,int temp){
        if(node==nullptr) return;
        temp=temp*10+node->val;
        
        if(node->left==nullptr && node->right==nullptr){
            sum+=temp;
        }
        else{
            dfs(node->left,sum,temp);
            dfs(node->right,sum,temp);
        }
    }
    int sumNumbers(TreeNode* root) {
        int sum=0;
        dfs(root,sum,0);
        return sum;
    }
};