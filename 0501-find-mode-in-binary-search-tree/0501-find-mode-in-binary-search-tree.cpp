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
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        TreeNode* curr=root;
        TreeNode* preval=nullptr;
        int max_count=0;
        int count=0;
        
        while(curr!=NULL){
            if(curr->left==NULL){

                if(preval!=NULL && preval->val==curr->val) count++;
                else count=1;
                if(count>max_count){
                    res.clear();
                    res.push_back(curr->val);
                    max_count=count;
                }
                else if(count==max_count) res.push_back(curr->val);
                
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

                    if(preval!=NULL && preval->val==curr->val) count++;
                    else count=1;
                    if(count>max_count){
                        res.clear();
                        res.push_back(curr->val);
                        max_count=count;
                    }
                    else if(count==max_count) res.push_back(curr->val);
                    preval=curr;

                    curr=curr->right;
                }
            }
        }
        return res;
    }
};