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
    int dfs(TreeNode* root,int maxm){
        if(!root)
            return 0;
        int count=0;
        if(root->val>=maxm)
            count=1;
        maxm=max(maxm,root->val);
        if(root->left)
            count+=dfs(root->left,maxm);
        if(root->right)
            count+=dfs(root->right,maxm);
        return count;
    }
    int goodNodes(TreeNode* root) {
        return dfs(root,root->val);
    }
};