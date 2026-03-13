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
    bool isEvenOddTree(TreeNode* root) {
       queue<TreeNode*> q;
       q.push(root);
       bool even=true;
       while(!q.empty()){
        int prev;
        if(even)
            prev=INT_MIN;
        else
            prev=INT_MAX;
        int n=q.size();     //n elements at a level
        while(n--){
            TreeNode* curr=q.front();
            q.pop();
            if(even&&(curr->val%2==0||prev>=curr->val))
                return false;
            if(!even&&(curr->val%2!=0||prev<=curr->val))
                return false;
            prev=curr->val;
            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);
        }
        even=!even;     //next level
       } 
       return true;
    }
};