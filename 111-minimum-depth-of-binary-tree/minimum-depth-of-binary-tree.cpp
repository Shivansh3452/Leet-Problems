/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int dfs(TreeNode* root, int dep) {
        if (!root)
            return INT_MAX;
        if (!root->left && !root->right)
            return dep;
        int lft = dfs(root->left, dep + 1);
        int rght = dfs(root->right,dep + 1);
        return min(lft,rght);
    }
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        
        return dfs(root,1);
    }
};