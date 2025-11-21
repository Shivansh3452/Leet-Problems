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

    int minm=INT_MAX;
    TreeNode* prev=NULL;
    int minDiffInBST(TreeNode* root) {
        if(root==NULL)
            return minm;
        minDiffInBST(root->left);
        if(prev){
            minm=min(minm,abs(root->val-prev->val));
        }
        prev=root;
        minDiffInBST(root->right);
        return minm;
    }
};