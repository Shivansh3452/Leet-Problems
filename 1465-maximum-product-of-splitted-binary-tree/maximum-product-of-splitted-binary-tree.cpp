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

    long long sum=0;
    long long maxP=0;
    long long totalsum(TreeNode* root){
        if(!root)
            return 0;
        long long leftsum=totalsum(root->left);
        long long rightsum=totalsum(root->right);
        long subtreesum=root->val+leftsum+rightsum;
        if(sum!=0){
            long long remainingsubtreesum=sum-subtreesum;
            maxP=max(maxP,subtreesum*remainingsubtreesum);
        }
        return subtreesum;
    }
    int maxProduct(TreeNode* root) {
        if(!root)
            return 0;
        sum=totalsum(root);
        totalsum(root);
        return maxP%1000000007;
    }
};