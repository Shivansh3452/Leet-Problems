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

    TreeNode* helper(int inst,int inend,int postst,int postend,vector<int>& inorder, vector<int>& postorder){
        if(inst>inend)
            return NULL;
        int root_candidate=postorder[postend];
        TreeNode* root=new TreeNode(root_candidate);
        int i=inst;
        for(;i<=inend;i++){
            if(inorder[i]==root->val)
               break; 
        }
        int leftsize=i-inst;
        root->left=helper(inst,i-1,postst,postst+leftsize-1,inorder,postorder);
        root->right=helper(i+1,inend,postst+leftsize,postend-1,inorder,postorder);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int inst=0;
        int inend=inorder.size()-1;
        int postst=0;
        int postend=postorder.size()-1;
        return helper(inst,inend,postst,postend,inorder,postorder);
    }
};