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

    TreeNode* helper(TreeNode* root,vector<TreeNode*>& res,set<int> st){
        if(!root)
            return nullptr;
        root->left=helper(root->left,res,st);
        root->right=helper(root->right,res,st);
        if(st.find(root->val)!=st.end()){
            if(root->left)    
                res.push_back(root->left);
            if(root->right)    
                res.push_back(root->right);
            return nullptr;
        }
        return root;
        
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> res;
        set<int> st;
        for(auto& num:to_delete)
            st.insert(num);
        root=helper(root,res,st);
        // if(st.find(root->val)!=st.end())
        //     res.push_back(root);
        if(root)
            res.push_back(root);
        return res;
    }
};