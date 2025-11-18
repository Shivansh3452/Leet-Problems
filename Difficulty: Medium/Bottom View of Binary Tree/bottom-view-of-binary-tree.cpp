/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        vector<int> ans;
        queue<pair<Node*,int>> q;
        map<int,int> mpp;
        q.push({root,0});
        while(q.size()>0){
            Node* curr=q.front().first;
            int currDist=q.front().second;
            q.pop();
            
            mpp[currDist]=curr->data;       //key=dist form root\\val=Node data
            if(curr->left!=NULL){
                q.push({curr->left,currDist-1});
            }
            if(curr->right!=NULL){
                q.push({curr->right,currDist+1});
            }
        }
        for(auto& it:mpp){
            ans.push_back(it.second);
        }
        return ans;
    }
};