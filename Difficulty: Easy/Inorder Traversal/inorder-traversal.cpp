/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
  vector<int> ans;
    vector<int> inOrder(Node* root) {
        if(root==NULL)
            return ans;
        inOrder(root->left);
        ans.push_back(root->data);
        inOrder(root->right);
        return ans;
    }
};