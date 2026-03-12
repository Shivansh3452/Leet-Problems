// User function Template for C++

/*// A Tree node
struct Node
{
    int key;
    struct Node *left, *right;
};*/

class Solution {
  public:
  
    void helper(int i,Node *root,int sum,vector<vector<int>>& ans,vector<int>& temp){ 
        if(!root)
            return;
        i+=root->key;
        temp.push_back(root->key);
        if(i==sum){
            ans.push_back(temp); 
        }
        
        if(root->left){
            helper(i,root->left,sum,ans,temp);
        }
        if(root->right){
            helper(i,root->right,sum,ans,temp);
        }
        temp.pop_back();
    }
    vector<vector<int>> printPaths(Node *root, int sum) {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(0,root,sum,ans,temp);
        return  ans;
    }
};