class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        int n=adj.size();
        queue<int> q;
        vector<bool> vis(n,false);
        vector<int> ans;
        q.push(0);
        ans.push_back(0);
        vis[0]=true;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(auto& it: adj[curr]){
                if(!vis[it]){
                    q.push(it);
                    vis[it]=true;
                    ans.push_back(it);
                }
            }
        }
        return ans;
    }
};