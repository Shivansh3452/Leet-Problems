/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int helper(struct TreeNode* root){
    if(!root)
        return 0;
    int left=helper(root->left);
    int right=helper(root->right);
    if(left==-1||right==-1)
        return -1;
    if(abs(left-right)>1)
        return -1;
    return 1 + (left > right ? left : right);
}
bool isBalanced(struct TreeNode* root) {
    return helper(root)>=0;
}