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

    TreeNode* helper(TreeNode* root,int val,int curr,int depth){
        if(!root)
            return nullptr;
        if(depth==1){
            TreeNode* newNode=new TreeNode(val);
            newNode->left=root;
            return newNode;
        }
        if(curr==depth-1){
            TreeNode* lefter=root->left;
            TreeNode* righter=root->right;
            TreeNode* newleft=new TreeNode(val);
            root->left=newleft;
            newleft->left=lefter;
            newleft->right=nullptr;

            TreeNode* newright=new TreeNode(val);
            root->right=newright;
            newright->right=righter;
            newright->left=nullptr;
            return root;
        }
        root->left=helper(root->left,val,curr+1,depth);
        root->right=helper(root->right,val,curr+1,depth);
        
        return root;
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        int curr=1;
        return helper(root,val,curr,depth);
    }
};