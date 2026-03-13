/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    vector<vector<Node*>> paths;
    void solve(Node* root,vector<Node*>& temp){
        if(!root)
            return;
        temp.push_back(root);
        if(!root->left&&!root->right){
            paths.push_back(temp);
        }
        solve(root->left,temp);
        solve(root->right,temp);
        temp.pop_back();
    }
    int kthFromLeaf(Node* root, int k) {
        vector<Node*> temp;
        solve(root,temp);
        unordered_set<Node*> result;
        for(vector<Node*>& path:paths){
            int n=path.size();
            if(n>k)
                result.insert(path[n-k-1]);
        }
        return result.size();
    }
};