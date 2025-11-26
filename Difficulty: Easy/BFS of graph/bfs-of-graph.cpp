class Solution {
public:
    vector<int> bfs(vector<vector<int>> &mp) {
        int V = mp.size();
        vector<bool> visited(V, false);
        vector<int> result;

        queue<int> q;
        q.push(0);
        visited[0] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            result.push_back(u);

            for (int v : mp[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }

        return result;
    }
};
