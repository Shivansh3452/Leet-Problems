/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
  
    Node *solver(vector<int> inorder, vector<int> preorder,int start,int end,int& idx){
        if(start>end)
            return NULL;
        int rootVal=preorder[idx];
        int i=start;
        for(;i<=end;i++){
            if(inorder[i]==rootVal){
                break;
            }
        }
        idx++;
        Node* root=new Node(rootVal);
        root->left=solver(inorder,preorder,start,i-1,idx);
        root->right=solver(inorder,preorder,i+1,end,idx);

        return root;
    }  
    
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        // code here
        int idx=0;  //for traversal in the preorder 
        int n=preorder.size();
        
        return solver(inorder,preorder,0,n-1,idx);
    }
};