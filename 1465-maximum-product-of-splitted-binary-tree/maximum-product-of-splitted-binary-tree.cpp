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

    long sum=0;
    long maxP=0;
    int totalsum(TreeNode* root){
        if(!root)
            return 0;
        return root->val+totalsum(root->left)+totalsum(root->right);
    }
    int find(TreeNode* root){
        if(!root)
            return 0;
        int leftsum=find(root->left);
        int rightsum=find(root->right);
        long subtreesum=root->val+leftsum+rightsum;
        long remainingsubtreesum=sum-subtreesum;
        maxP=max(maxP,subtreesum*remainingsubtreesum);
        return subtreesum;
    }
    int maxProduct(TreeNode* root) {
        if(!root)
            return 0;
        maxP=0;
        sum=totalsum(root);
        find(root);
        return maxP%1000000007;
    }
};