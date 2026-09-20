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
    void bfs(TreeNode* root,vector<int>& temp,vector<vector<int>>& ans){
        if(!root){
            ans.push_back(temp);
            return;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            while(n--){
                TreeNode* node=q.front();
                q.pop();
                temp.push_back(node->val);
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            ans.push_back(temp);
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        if(!root)
            return {};
        vector<vector<int>> ans;
        vector<int> temp;
        bfs(root,temp,ans);
        vector<int> res;
        for(auto& it: ans){
            res.push_back(it[it.size()-1]);
        }
        return res;
    }
};