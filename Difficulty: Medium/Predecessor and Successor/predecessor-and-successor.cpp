/* BST Node
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    vector<int> inorder(Node* root,vector<int>& ans){
        if(root==NULL){
            return ans;
        }
        inorder(root->left,ans);
        ans.push_back(root->data);
        inorder(root->right,ans);
        
        return ans;
    }
    Node* findNode(Node* root,int val){
        if(root==NULL || val==-1){
            return NULL;
        }
        if(root->data==val){
            return root;
        }
        if(val<root->data) 
            return findNode(root->left,val);
        return findNode(root->right,val);
    }
    vector<Node*> findPreSuc(Node* root, int key) {
        vector<Node*> res;
        vector<int> ans;
        inorder(root,ans);
        int predecessor=-1;
        int successor=-1;
        for(int i=0;i<ans.size();i++){
            
            if(ans[i]<key){
                predecessor=ans[i];
            }
            if(ans[i]>key && successor==-1){
                successor=ans[i];
                break;
            }
        }
        res.push_back(findNode(root,predecessor));
        res.push_back(findNode(root,successor));
        return res;
        
    }
};