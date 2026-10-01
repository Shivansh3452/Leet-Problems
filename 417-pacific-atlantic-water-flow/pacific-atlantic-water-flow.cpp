class Solution {
public:
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    void dfs(int i,int j,int m,int n,int prev,vector<vector<bool>>& visited,vector<vector<int>>& heights){
        if(i<0||j<0||i>=m||j>=n||visited[i][j]||heights[i][j]<prev)
            return;
        visited[i][j]=true;
        for(auto& it: directions){
            int i_=i+it[0];
            int j_=j+it[1];
            dfs(i_,j_,m,n,heights[i][j],visited,heights);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<int>> ans;
        vector<vector<bool>> pacific(m,vector<bool>(n,false));
        vector<vector<bool>> atlantic(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            dfs(i,0,m,n,INT_MIN,pacific,heights);
        }
        for(int j=0;j<n;j++){
            dfs(0,j,m,n,INT_MIN,pacific,heights);
        }
        for(int i=0;i<m;i++){
            dfs(i,n-1,m,n,INT_MIN,atlantic,heights);
        }
        for(int j=0;j<n;j++){
            dfs(m-1,j,m,n,INT_MIN,atlantic,heights);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pacific[i][j]&&atlantic[i][j])
                    ans.push_back({i,j});
            }
        }
        return ans;
    }
};