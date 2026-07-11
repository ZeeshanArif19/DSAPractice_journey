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
    int sumEvenGrandparent(TreeNode* root) {
        if(root==NULL) return 0;
        
        queue<pair<TreeNode*,pair<TreeNode*,TreeNode*>>> q;  //curr,parent,grandparent
        q.push({root,{NULL,NULL}});

        TreeNode* curr=NULL;
        TreeNode* parent=NULL;
        TreeNode* grandparent=NULL;
        int sum=0;

        while(!q.empty()){
            auto front=q.front();
            q.pop();
            curr=front.first;
            parent=front.second.first;
            grandparent=front.second.second;

            if(grandparent!=NULL && grandparent->val%2==0){
                sum+=curr->val;
            }
            if(curr->left){
                q.push({curr->left,{curr,parent}});
            }
            if(curr->right){
                q.push({curr->right,{curr,parent}});
            }
        }
        return sum;
    }
};