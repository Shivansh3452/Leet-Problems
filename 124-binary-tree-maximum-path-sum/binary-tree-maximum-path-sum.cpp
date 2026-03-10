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
    int maxSum;
    int helper(TreeNode* root){
        if(!root)
            return 0;
        int l=helper(root->left);
        int r=helper(root->right);
        int if_negatn_at_any_one_node=max(l,r)+root->val;
        int both_l_r_plus=l+r+root->val;
        int both_l_r_negatn=root->val;

        maxSum=max({maxSum,if_negatn_at_any_one_node,both_l_r_plus,both_l_r_negatn});
        return max(if_negatn_at_any_one_node,both_l_r_negatn);
    }
    int maxPathSum(TreeNode* root) {
        maxSum=INT_MIN;
        helper(root);
        return maxSum;
    }
};