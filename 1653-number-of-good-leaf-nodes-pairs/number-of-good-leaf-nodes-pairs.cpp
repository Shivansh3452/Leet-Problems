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

    vector<int> helper(TreeNode* root,int& distance,int& count){
        if(!root)
            return {0};
        if(!root->left&&!root->right)
            return {1};
        vector<int> left_d=helper(root->left,distance,count);
        vector<int> right_d=helper(root->right,distance,count);
        
        for(auto& l:left_d){
            for(auto& r:right_d){
                if(l!=0&&r!=0&&l+r<=distance)
                    count++;
            }
        }
        vector<int> curr;
        for(auto& l:left_d){
            if(l!=0&&l+1<=distance)
                curr.push_back(l+1);
        }
        for(auto& r:right_d){
            if(r!=0&&r+1<=distance)
                curr.push_back(r+1);
        }
        return curr;
    }
    int countPairs(TreeNode* root, int distance) {
        int count=0;
        helper(root,distance,count);
        return count;
    }
};