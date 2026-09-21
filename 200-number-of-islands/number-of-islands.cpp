class Solution {
public:
    void dfs(int i,int j,int m,int n,vector<vector<bool>>& visited,vector<vector<char>>& grid){
        if(i>=m||j>=n||i<0||j<0||visited[i][j]||grid[i][j]=='0')
            return;
        visited[i][j]=true;
        dfs(i+1,j,m,n,visited,grid);
        dfs(i,j+1,m,n,visited,grid);
        dfs(i-1,j,m,n,visited,grid);
        dfs(i,j-1,m,n,visited,grid);
        // return dfs(i+1,j,m,n,visited,grid)+dfs(i,j+1,m,n,visited,grid)+dfs(i-1,j,m,n,visited,grid)+dfs(i,j-1,m,n,visited,grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        //find the number of connected components
        int ans=0;
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j]&&grid[i][j]=='1'){
                    dfs(i,j,m,n,visited,grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};