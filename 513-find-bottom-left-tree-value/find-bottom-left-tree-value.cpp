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

    int maxDepth,bottomLeftVal;
    void dfs(TreeNode* curr,int depth){
        if(!curr)
            return;
        if(depth>maxDepth){
            bottomLeftVal=curr->val;
            maxDepth=depth;
        }
        dfs(curr->left,depth+1);
        dfs(curr->right,depth+1);
    }
    int findBottomLeftValue(TreeNode* root) {
        maxDepth=-1;
        bottomLeftVal=0;
        dfs(root,0);
        return bottomLeftVal;
    }
};