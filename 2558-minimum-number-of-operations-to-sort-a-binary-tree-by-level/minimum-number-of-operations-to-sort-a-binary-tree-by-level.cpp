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
private:
    int helper(vector<int>& temp){
        int ans=0;
        vector<int> copy=temp;
        sort(copy.begin(),copy.end());
        unordered_map<int,int> pos;
        for(int i=0;i<temp.size();i++)
            pos[temp[i]]=i;
        for(int i=0;i<temp.size();i++){
            if(temp[i]!=copy[i]){
                ans++;
                int currPos=pos[copy[i]];
                pos[temp[i]]=currPos;
                swap(temp[currPos],temp[i]);
            }
        }
        return ans;
    }
public:
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        int swaps=0;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int> temp;
            while(n--){
                TreeNode* curr=q.front();
                q.pop();
                temp.push_back(curr->val);
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
            swaps+=helper(temp);
        }
        return swaps;
    }
};