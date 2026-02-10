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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root,0});
        unsigned long long width=0;

        while(!q.empty()){
            unsigned long long leftInd,rightInd;
            int size=q.size();
            
            for(int i=0;i<size;i++){
                TreeNode* node=q.front().first;
                unsigned long long currindex=q.front().second;
                q.pop();
                
                if(i==0) leftInd=currindex;
                if(i==size-1) rightInd=currindex;

                if(node->left!=nullptr) q.push({node->left,currindex*2+1});
                if(node->right!=nullptr) q.push({node->right,currindex*2+2});
    
            }
            width=max(width,rightInd-leftInd+1);
        }
        return width;
    }
};