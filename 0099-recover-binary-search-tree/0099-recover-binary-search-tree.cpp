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
    void recoverTree(TreeNode* root) {
        TreeNode* curr=root;
        TreeNode* lastvis=nullptr;
        TreeNode* first=nullptr;
        TreeNode* second=nullptr;

        while(curr!=NULL){
            if(curr->left==NULL){

                if(lastvis!=nullptr && lastvis->val>curr->val){
                    if(first==NULL) first=lastvis;
                    second=curr;
                }
                lastvis=curr;

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

                    if(lastvis!=nullptr && lastvis->val>curr->val){
                        if(first==NULL) first=lastvis;
                        second=curr;
                    }
                    lastvis=curr;

                    curr=curr->right;
                }
            }
        }
        swap(first->val,second->val);
    }
};