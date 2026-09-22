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
void helper(TreeNode* newNode,TreeNode* root){
    if(!root)
        return;
    if(root->right){
        newNode->left=new TreeNode(root->right->val);
        helper(newNode->left,root->right);
    }
    if(root->left){
        newNode->right=new TreeNode(root->left->val);
        helper(newNode->right,root->left);
    }
}
TreeNode* invertTree(TreeNode* root) {
    if(!root)
        return nullptr;
    TreeNode* newNode=new TreeNode(root->val);
    helper(newNode,root);
    return newNode;
}
};