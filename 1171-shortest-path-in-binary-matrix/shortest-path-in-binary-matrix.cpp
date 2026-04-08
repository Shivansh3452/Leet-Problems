class Solution {
public:
    bool isSafe(int len, int wid, int n) {
        return len < n && wid < n && len >= 0 && wid >= 0;
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        queue<pair<int, int>> q;
        if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0)
            return -1;
        vector<pair<int, int>> dir = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                                      {0, 1},   {1, -1}, {1, 0},  {1, 1}};

        q.push({0, 0});
        grid[0][0] = 1;
        ans++;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto it = q.front();
                q.pop();
                int len = it.first;
                int wid = it.second;
                if (len == n - 1 && wid == n - 1)
                    return ans;

                for (auto& it : dir) {
                    int nr = len + it.first;
                    int nc = wid + it.second;
                    if (isSafe(nr, nc, n) && grid[nr][nc] == 0) {
                        grid[nr][nc] = 1;
                        q.push({nr, nc});
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};