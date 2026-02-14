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
    int getMinimumDifference(TreeNode* root) {
        int mindiff=INT_MAX;
        int diff=0;
        TreeNode* curr=root;
        TreeNode* preval=nullptr;
        
        while(curr!=NULL){
            if(curr->left==NULL){
                if(preval){
                    diff=abs(preval->val-curr->val);
                    mindiff=min(mindiff,diff);
                }
                preval=curr;
                curr=curr->right;
            }
            else{
                TreeNode* prev=curr->left;
                while(prev->right!=NULL && prev->right!=curr){
                    prev=prev->right;
                }
                if(prev->right==NULL){
                    prev->right=curr;
                    curr=curr->left;
                }
                else{
                    prev->right=NULL;
                    if(preval){
                        diff=abs(preval->val-curr->val);
                        mindiff=min(mindiff,diff);
                    }
                    preval=curr;
                    curr=curr->right;
                }
            }
        }
        return mindiff;
    }
};