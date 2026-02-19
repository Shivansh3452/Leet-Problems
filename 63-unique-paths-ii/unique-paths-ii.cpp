class Solution {
public:
    int t[101][101];
    int helper(int i,int j,int m,int n,vector<vector<int>>& obstacleGrid){
        if(i>=m||j>=n||i<0||j<0||obstacleGrid[i][j]==1)
            return t[i][j]=0;
        if(t[i][j]!=-1)
            return t[i][j];
        if(i==m-1&&j==n-1)
            return t[i][j]=1;
        int right=helper(i,j+1,m,n,obstacleGrid);
        int down=helper(i+1,j,m,n,obstacleGrid);
        return t[i][j]=right+down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        memset(t,-1,sizeof(t));
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        return helper(0,0,m,n,obstacleGrid);
    }
};