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
    unordered_map<int,int> inmap;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0;i<inorder.size();i++){
            inmap[inorder[i]]=i;
        }
        
        return build(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1);
    }
    TreeNode* build(vector<int> &postorder,int postStart,int postEnd,
        vector<int> &inorder,int inStart,int inEnd){
        
        if(postStart>postEnd || inStart>inEnd) return NULL;
        
        TreeNode* root=new TreeNode(postorder[postEnd]);
        int rootInd=inmap[root->val];
        int leftsize=rootInd-inStart;

        root->left=build(postorder,postStart,postStart+leftsize-1, inorder,inStart,rootInd-1);
        root->right=build(postorder,postStart+leftsize,postEnd-1, inorder,rootInd+1,inEnd);

        return root;
    }
};