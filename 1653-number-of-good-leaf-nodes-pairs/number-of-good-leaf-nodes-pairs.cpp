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

    void makeGraph(TreeNode* root,TreeNode* prev,unordered_map<TreeNode*,vector<TreeNode*>>& adj,unordered_set<TreeNode*>& st){
        if(!root)
            return;
        if(!root->left&&!root->right)
            st.insert(root);        //leaf node
        if(prev){
            adj[root].push_back(prev);
            adj[prev].push_back(root);
        }
        makeGraph(root->left,root,adj,st);
        makeGraph(root->right,root,adj,st);
    }
    int countPairs(TreeNode* root, int distance) {
        unordered_map<TreeNode*,vector<TreeNode*>>adj;
        unordered_set<TreeNode*>st;

        makeGraph(root,nullptr,adj,st); 

        int count=0;    //count good nodes pair
        for(auto& leaf:st){
            //BFS hit and see if you can find another leaf nodes within distance
            queue<TreeNode*> q;
            unordered_set<TreeNode*> visited;
            q.push(leaf);
            visited.insert(leaf);

            for(int level=0;level<=distance;level++){//dist se >wale ko kyohi loge
                int n=q.size();
                while(n--){
                    TreeNode* curr=q.front();
                    q.pop();
                    if(curr!=leaf&&st.count(curr)){
                        count++;
                    }
                    for(auto& ngbr:adj[curr]){
                        if(!visited.count(ngbr)){
                            q.push(ngbr);
                            visited.insert(ngbr);
                        }
                    }
                }
            }
        }
        return count/2;
    }
};