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

    void solver(TreeNode* root,vector<string>& s,string c){
        if(root==NULL){
            return;
        }
        c+=to_string(root->val);
        if(root->left==NULL && root->right==NULL){
            s.push_back(c);
        }
        else{
            c+="->";
            solver(root->left,s,c);
            solver(root->right,s,c);
        }
        
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> s;
        string c;
        solver(root,s,c);
        return s;
    }
};