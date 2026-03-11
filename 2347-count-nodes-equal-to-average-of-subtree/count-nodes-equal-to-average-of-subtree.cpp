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

    int count=0;
    pair<int,int> helper(TreeNode* root){
        if(!root)
            return {0,0};
        pair<int,int> lft=helper(root->left);
        pair<int,int> rght=helper(root->right);
        int lft_node_and_rght_sum=lft.first+rght.first+root->val;
        int nodecount=lft.second+rght.second+1;

        if(root->val==lft_node_and_rght_sum/nodecount)
            count++;
        return {lft_node_and_rght_sum,nodecount};
    }
    int averageOfSubtree(TreeNode* root) {
        if(!root)
            return 0;
        helper(root);
        return count;
    }
};