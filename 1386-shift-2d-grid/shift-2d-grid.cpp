class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        k=k%(m*n);
        vector<vector<int>> ans(m,vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int idx=i*n+j;
                int nxt=(idx+k)%(m*n);
                ans[nxt/n][nxt%n]=grid[i][j];
            }
        }
        return ans;
    }
};