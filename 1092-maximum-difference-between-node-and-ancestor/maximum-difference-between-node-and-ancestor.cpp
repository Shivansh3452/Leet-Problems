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
    int helper(TreeNode* root,int minm,int maxm){
        if(!root)
            return abs(maxm-minm);
        minm=min(minm,root->val);
        maxm=max(maxm,root->val);
        int lft=helper(root->left,minm,maxm);
        int rght=helper(root->right,minm,maxm);
        return max(lft,rght);
    }
    int maxAncestorDiff(TreeNode* root) {
        return helper(root,root->val,root->val);
    }
};