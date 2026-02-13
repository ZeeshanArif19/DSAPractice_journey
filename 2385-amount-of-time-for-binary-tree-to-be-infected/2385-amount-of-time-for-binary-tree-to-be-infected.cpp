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
    void markParent(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &parentTrack,TreeNode* &source,int &start){
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();

            if(start==node->val) source=node;
            if(node->left){
                q.push(node->left);
                parentTrack[node->left]=node;
            }
            if(node->right){
                q.push(node->right);
                parentTrack[node->right]=node;
            }
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        TreeNode* source=nullptr;
        unordered_map<TreeNode*,TreeNode*> parentTrack;
        markParent(root,parentTrack,source,start);

        queue<TreeNode*> q;
        unordered_map<TreeNode*,bool> vis;
        q.push(source);
        vis[source]=true;
        int time=0;

        while(!q.empty()){
            int size=q.size();
            time++;

            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();

                if(node->left && !vis[node->left]){
                    q.push(node->left);
                    vis[node->left]=true;
                }
                if(node->right && !vis[node->right]){
                    q.push(node->right);
                    vis[node->right]=true;
                }
                if(parentTrack[node] && !vis[parentTrack[node]]){
                    q.push(parentTrack[node]);
                    vis[parentTrack[node]]=true;
                }
            }
        }
        return time-1;
    }
};