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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode* curr=root;
        while(curr){    //jab lefft hai to left me pehle operation hoga
            if(curr->left){
                TreeNode* lft=curr->left;
                while(lft->right!=NULL)
                    lft=lft->right;
                lft->right=curr;
                TreeNode* temp=curr;
                curr=curr->left;
                temp->left=NULL;
            }
            else{   //jab left nhi h i.e., left me operation ho chuka h
                res.push_back(curr->val);
                curr=curr->right;
            }
        }
        return res;
    }
};