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

    int helper(int val,TreeNode* root){
        if(!root)
            return 0;
        val=(2*val)+root->val;
        if(root->left==NULL&& root->right==NULL)
            return val;
        return helper(val,root->left)+helper(val,root->right);
    }
    int sumRootToLeaf(TreeNode* root) {
       return helper(0,root); 
    }
};