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

    int helperdepth(TreeNode* root){
        if(!root)
            return 0;
        return 1+max(helperdepth(root->left),helperdepth(root->right));
    }
    vector<TreeNode*> bfs(TreeNode* root,int& depth){
        queue<TreeNode*> q;
        q.push(root);
        int currdepth=1;
        while(!q.empty()){
            int n=q.size();
            if(currdepth==depth){
                vector<TreeNode*> ans;
                for(int i=0;i<n;i++){
                    TreeNode* curr=q.front();
                    q.pop();
                    ans.push_back(curr);
                }
                return ans;
            }
            while(n--){
                TreeNode* curr=q.front();
                q.pop();
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
            currdepth++;
        }
        return {};
    }
    TreeNode* lca(TreeNode* root,vector<TreeNode*>& leaves){
        if(!root)
            return nullptr;
        for(TreeNode* leaf:leaves){
            if(root==leaf)
                return root;
        }
        TreeNode* lft=lca(root->left,leaves);
        TreeNode* rght=lca(root->right,leaves);

        if(lft&&rght)
            return root;
        if(lft)
            return lft;
        return rght;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int depth=helperdepth(root);
        vector<TreeNode*> leaves=bfs(root,depth);
        TreeNode* ans=lca(root,leaves);
        return ans;
    }
};