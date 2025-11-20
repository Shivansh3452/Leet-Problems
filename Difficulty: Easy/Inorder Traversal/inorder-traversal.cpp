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
    vector<int> inOrder(Node* root) {
        vector<int> ans;
        Node* curr=root;
        
        while(curr!=NULL){
            if(curr->left==NULL){
                ans.push_back(curr->data);
                curr=curr->right;
            }
            else{
                Node* leftChild=curr->left;
                while(leftChild->right!=NULL){
                    leftChild=leftChild->right;
                }
                leftChild->right=curr;
                Node* temp=curr;
                curr=curr->left;
                temp->left=NULL;
            }
        }
        return ans;
        
    }
};