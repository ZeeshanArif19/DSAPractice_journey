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
    vector<TreeNode*> solve(int n,unordered_map<int,vector<TreeNode*>> &dp){
        vector<TreeNode*> allTrees;
        if(dp.find(n)!=dp.end()) return dp[n];
        if(n%2==0){ //even nodes can never form full trees
            return dp[n]={};
        }
        if(n==1){
            return dp[n]={new TreeNode(0)}; //1 node can form a full tree
        }
        
        for(int i=1;i<n;i++){
            vector<TreeNode*> leftFT=solve(i,dp); //no of nodes in left subtree
            vector<TreeNode*> rightFT=solve(n-i-1,dp); //no of nodes in right subtree
            
            for(TreeNode* left:leftFT){  //criss-cross every node from the left and right subtrees
                for(TreeNode* right:rightFT){
                    TreeNode* root=new TreeNode(0);
                    root->left=left;
                    root->right=right;
                    allTrees.push_back(root);
                }
            }
        }
        return dp[n]=allTrees;
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        unordered_map<int,vector<TreeNode*>> dp;
        return solve(n,dp);
    }
};