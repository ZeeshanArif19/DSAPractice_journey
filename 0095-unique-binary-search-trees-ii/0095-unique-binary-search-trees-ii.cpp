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
    vector<TreeNode*> solve(int start,int end,map<pair<int,int>,vector<TreeNode*>> &dp){
        vector<TreeNode*> all_trees;

        if(dp.find({start,end})!=dp.end()){
            return dp[{start,end}];
        }
        if(start>end){
            all_trees.push_back(nullptr);
            return dp[{start,end}]=all_trees;
        }
        
        for(int i=start;i<=end;i++){
            vector<TreeNode*> leftBST=solve(start,i-1,dp);
            vector<TreeNode*> rightBST=solve(i+1,end,dp);

            for(TreeNode* left: leftBST){
                for(TreeNode* right:rightBST){
                    TreeNode* root=new TreeNode(i);
                    root->left=left;
                    root->right=right;
                    all_trees.push_back(root);
                }
            }
        }
        return dp[{start,end}]=all_trees;
    }
    vector<TreeNode*> generateTrees(int n) {
        map<pair<int,int>,vector<TreeNode*>> dp;
        return solve(1,n,dp);
    }
};