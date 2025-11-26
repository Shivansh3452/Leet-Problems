class Solution {
  public:

    void solver(int node, vector<vector<int>> &adj, vector<int> &visited, vector<int> &ans) {
        ans.push_back(node);
        visited[node] = 1;

        for (auto &i : adj[node]) {
            if (!visited[i]) {
                solver(i, adj, visited, ans);
            }
        }
    }
  
    vector<int> dfs(vector<vector<int>>& adj) {

        int V = adj.size();
        vector<int> visited(V, 0);
        vector<int> ans;

        // DFS always starts from node 0 in GFG dfs problem
        solver(0, adj, visited, ans);

        return ans;
    }
};
