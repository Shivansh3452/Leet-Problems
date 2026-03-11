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

    map<int,int> mpp;
    void dfs(TreeNode* root,int level){
        if(!root)
            return;
        mpp[level]+=root->val;
        dfs(root->left,level+1);
        dfs(root->right,level+1);
    }
    int maxLevelSum(TreeNode* root) {
        dfs(root,1);
        int maxSum=INT_MIN;
        int reslvl=1;
        for(auto& it:mpp){
            int lvl=it.first;
            int sum=it.second;
            if(sum>maxSum){
                maxSum=sum;
                reslvl=it.first;
            }
        }
        return reslvl;
    }
};