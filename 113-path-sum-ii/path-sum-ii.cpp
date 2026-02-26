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
    vector<vector<int>> res;
    vector<int> temp;
    void helper(TreeNode* root,int sum,int targetSum){
        if(!root)
            return;
        sum+=root->val;
        temp.push_back(root->val);
        if(root->left==NULL&&root->right==NULL&&sum==targetSum){
            res.push_back(temp);
        }
        else{
            helper(root->left,sum,targetSum);
            helper(root->right,sum,targetSum);
        }
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int sum=0;
        helper(root,sum,targetSum);
        return res;
    }
};