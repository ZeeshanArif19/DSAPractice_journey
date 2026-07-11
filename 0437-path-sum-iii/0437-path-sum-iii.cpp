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
    int solve(TreeNode* node,long long currsum,int target,unordered_map<long long,int> &mpp){
        if(node==NULL) return 0;
        currsum+=node->val;  //prefix sum

        int count=0;
        if(mpp.find(currsum-target)!=mpp.end()){ //if currsum-target exists add its frequency to ans
            count+=mpp[currsum-target]; 
        }
        mpp[currsum]++; //we keep it after the increment because if the target is 0 the current node mathched with itself.
        
        int left=solve(node->left,currsum,target,mpp);
        int right=solve(node->right,currsum,target,mpp);
        mpp[currsum]--; //backtrack the running sum as the path can start and end anywhere

        return count+left+right;
    }
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long,int> mpp;
        long long currsum=0;
        mpp[0]=1;
        return solve(root,currsum,targetSum,mpp);
    }
};