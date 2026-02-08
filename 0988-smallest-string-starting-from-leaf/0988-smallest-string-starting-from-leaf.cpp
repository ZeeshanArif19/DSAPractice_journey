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
    string ans="";
    void dfs(TreeNode* node,string &res){
        if(node==NULL) return;
        
        res+=node->val+'a';
        if(node->left==nullptr && node->right==nullptr){
            string rtemp=res;
            reverse(rtemp.begin(),rtemp.end());
            if(ans.empty() || rtemp<ans){
                ans=rtemp;
            }
        }
        else{
            dfs(node->left,res);
            dfs(node->right,res);
        }
        res.pop_back();
    }
    string smallestFromLeaf(TreeNode* root) {
        string res="";
        dfs(root,res);
        return ans;
    }
};