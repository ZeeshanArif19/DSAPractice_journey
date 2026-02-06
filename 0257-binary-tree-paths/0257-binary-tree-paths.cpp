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
    void dfs(TreeNode* node,string path,vector<string> &res){
        if(node==nullptr) return;

        path+=to_string(node->val);
        path+="->";
        if(node->left==nullptr && node->right==nullptr){
            path.pop_back();
            path.pop_back();
            res.push_back(path);
        }
        else{
            dfs(node->left,path,res);
            dfs(node->right,path,res);
        }

    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        string path="";
        dfs(root,path,res);
        return res;
    }
};