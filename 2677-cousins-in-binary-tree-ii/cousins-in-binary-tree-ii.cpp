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
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> levelSum;
        q.push(root);
        //first we calculate the level Sum
        while(!q.empty()){
            int n=q.size();
            int currSum=0;
            while(n--){
                TreeNode* curr=q.front();
                q.pop();
                currSum+=curr->val;
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
            levelSum.push_back(currSum);
        }

        //Now q is empty onto next step of filling tree with reqd values
        q.push(root);
        root->val=0;    //root has no sibiling or cousin
        int i=1;    //for accessing the levelsum array
        while(!q.empty()){
            int n=q.size();
            while(n--){
                TreeNode* curr=q.front();
                q.pop();
                int sibilingSum=0;
                if(curr->left){
                    sibilingSum+=curr->left->val;
                }
                else
                    sibilingSum+=0;
                if(curr->right){
                    sibilingSum+=curr->right->val;
                }
                else
                    sibilingSum+=0;
                if(curr->left){
                    curr->left->val=levelSum[i]-sibilingSum;
                    q.push(curr->left);
                }
                if(curr->right){
                    curr->right->val=levelSum[i]-sibilingSum;
                    q.push(curr->right);
                }
            }
            i++;
        }
        return root;
    }
};