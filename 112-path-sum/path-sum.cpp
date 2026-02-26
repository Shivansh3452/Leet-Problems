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

    bool helper(TreeNode* root,int sum,int targetSum){
        if(!root)   
            return false;
        if(root->left==NULL&&root->right==NULL)
            return sum+root->val==targetSum;
        bool leftres=false;
        bool rightres=false;
        if(root->left)
            leftres= helper(root->left,sum+root->val,targetSum);
        if(root->right)
            rightres= helper(root->right,sum+root->val,targetSum);
        return leftres||rightres;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum=0;
        return helper(root,sum,targetSum);
    }
};