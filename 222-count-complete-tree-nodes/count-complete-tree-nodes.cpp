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

    int heightleft(TreeNode* root){
        if(!root)
            return 0;
        TreeNode* temp=root;
        int count=0;
        while(temp){
            temp=temp->left;
            count++;
        }
        return count;
    }
    int heightright(TreeNode* root){
        if(!root)
            return 0;
        TreeNode* temp=root;
        int count=0;
        while(temp){
            temp=temp->right;
            count++;
        }
        return count;
    }
    int countNodes(TreeNode* root) {
       int leftheight=heightleft(root);
       int rightheight=heightright(root);
       if(leftheight==rightheight){         //tree is complete and the height 
          return (pow(2,leftheight)-1);     //of complete tree is (2^height)-1
       }
       return countNodes(root->left)+countNodes(root->right)+1;
    }
};