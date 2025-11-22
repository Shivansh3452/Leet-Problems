/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/


class info{
    public:
      int maxi;
      int mini;
      bool isBst;
      int size;
};
class Solution {
  public:
  
  info solve(Node* root,int& ans){
      //base case
      if(root==NULL)
        return {INT_MIN,INT_MAX,true,0};
    info left=solve(root->left,ans);
    info right = solve(root->right, ans);
    info currNode;
    currNode.size=left.size+right.size+1;
    currNode.maxi=max(root->data,right.maxi);
    currNode.mini=min(root->data,left.mini);
    
    if(left.isBst && right.isBst && (root->data>left.maxi && root->data<right.mini)){
        currNode.isBst=true;
    }
    else{
        currNode.isBst=false;
    }   
    //ans update
    if(currNode.isBst){
        ans=max(ans,currNode.size);
    }
    return currNode;
  }
    
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root) {
        // Your code here
        int maxSize=0;
        info temp=solve(root,maxSize);
        return maxSize;
        
    }
};