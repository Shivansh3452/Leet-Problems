class Solution {
  public:
    vector<int> ans;
    void helper(int i,vector<bool>& vis,vector<vector<int>>& adj){
        vis[i]=true;
        ans.push_back(i);
        for(auto& it: adj[i]){
            if(!vis[it]){
                helper(it,vis,adj);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<bool> vis(n,false);
        helper(0,vis,adj);
        return ans;
    }
};