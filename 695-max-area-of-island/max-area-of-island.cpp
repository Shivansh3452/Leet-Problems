class Solution {
public:
    int ans=0;
    int dfs(int i,int j,int m,int n,vector<vector<bool>>& visited,vector<vector<int>>& grid){
        if(i>=m||j>=n||i<0||j<0||grid[i][j]==0||visited[i][j])
            return 0;
        visited[i][j]=true;
        grid[i][j]=0;
        return 1+dfs(i+1,j,m,n,visited,grid)+dfs(i,j+1,m,n,visited,grid)+dfs(i-1,j,m,n,visited,grid)+dfs(i,j-1,m,n,visited,grid);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]&&!visited[i][j])
                    ans=max(ans,dfs(i,j,m,n,visited,grid));
            }
        }
        return ans;
    }
};