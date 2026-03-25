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

    TreeNode* helper(int stpre,int endpre,int stpost,int endpost,vector<int>& preorder, vector<int>& postorder,unordered_map<int,int>& postIndex){
        if(stpre>endpre||stpost>endpost)
            return nullptr;
        TreeNode* root=new TreeNode(preorder[stpre]);
        if(stpre==endpre)
            return root;

        int leftval=preorder[stpre+1];
        int leftpos=postIndex[leftval];
        int leftSize=leftpos-stpost+1;
        root->left=helper(stpre+1,stpre+leftSize,stpost,leftpos,preorder,postorder,postIndex);
        root->right=helper(stpre+leftSize+1,endpre,leftpos+1,endpost-1,preorder,postorder,postIndex);
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n=preorder.size();
        unordered_map<int,int>postIndex;
        for (int i=0;i<n;i++) {
            postIndex[postorder[i]]=i;
        }
        return helper(0,n-1,0,n-1,preorder,postorder,postIndex);
    }
};