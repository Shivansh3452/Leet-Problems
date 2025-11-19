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

    TreeNode* solver(vector<int>& inorder, vector<int>& postorder,int start,int end,int &idx){
        if(start>end)
            return NULL;
        int rootdata=postorder[idx];
        idx--;      //move backwards in postorder
        int i=start;
        for(;i<=end;i++){
            if(inorder[i]==rootdata)
                break;
        }
        TreeNode* root=new TreeNode(rootdata);
        root->right=solver(inorder,postorder,i+1,end,idx);
        root->left=solver(inorder,postorder,start,i-1,idx);

        return root;
    }
    

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        int idx=n-1;

        return solver(inorder,postorder,0,n-1,idx);
    }
};