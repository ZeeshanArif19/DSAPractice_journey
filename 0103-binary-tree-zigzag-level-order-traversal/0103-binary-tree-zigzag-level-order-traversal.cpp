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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==nullptr) return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool isleft=true;

        while(!q.empty()){
            int size=q.size();
            vector<int> level;

            while(size--){
                TreeNode* node=q.front();
                q.pop();
                level.emplace_back(node->val);

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(isleft==false) reverse(level.begin(),level.end());
            ans.emplace_back(level);
            isleft=!isleft;
        }
        return ans;
    }
};