class Solution {
public:
    int t[101][101];
    int helper(int i,int j,int m,int n){
        if(i==m-1&& j==n-1)
            return 1;
        if(i<0||i>=m||j<0||j>=n)
            return 0;
        if(t[i][j]!=-1)
            return t[i][j];
        int right=helper(i,j+1,m,n);
        int down=helper(i+1,j,m,n);
        return t[i][j]=right+down;
    }
    int uniquePaths(int m, int n) {
        memset(t,-1,sizeof(t));
        return helper(0,0,m,n);
    }
};