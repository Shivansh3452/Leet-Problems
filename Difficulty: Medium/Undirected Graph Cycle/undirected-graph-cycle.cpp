class Solution {
  public:

    bool isCycleUntil(int v, unordered_map<int, vector<int>> &mpp,
                      vector<bool> &visited, int parent) {

        visited[v] = true;

        for (int i : mpp[v]) {
            if (!visited[i]) {
                if (isCycleUntil(i, mpp, visited, v)) {
                    return true;
                }
            }
            else if (i != parent) {
                return true;
            }
        }
        return false;
    }

    bool isCycle(int V, vector<vector<int>>& edges) {

        unordered_map<int, vector<int>> mpp;

        // Build adjacency list
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            mpp[u].push_back(v);
            mpp[v].push_back(u);
        }

        vector<bool> visited(V, false);

        // Check all components
        for (int u = 0; u < V; u++) {
            if (!visited[u]) {
                if (isCycleUntil(u, mpp, visited, -1)) {
                    return true;
                }
            }
        }

        return false;
    }
};
