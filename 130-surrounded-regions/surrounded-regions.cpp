class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>& nums,vector<vector<bool>>& vis){
        int n=nums.size();
        int m=nums[0].size();
        if(i<0||i>=n||j<0||j>=m)
            return;
        if(vis[i][j]||nums[i][j]=='X')
            return;
        vis[i][j]=true;
        dfs(i+1,j,nums,vis);
        dfs(i-1,j,nums,vis);
        dfs(i,j+1,nums,vis);
        dfs(i,j-1,nums,vis);
    }
    void solve(vector<vector<char>>& nums){
        int n=nums.size();
        int m=nums[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            if(nums[i][0]=='O')
                dfs(i,0,nums,vis);
            if(nums[i][m-1]=='O')
                dfs(i,m-1,nums,vis);
        }
        for(int j=0;j<m;j++){
            if(nums[0][j]=='O')
                dfs(0,j,nums,vis);

            if(nums[n-1][j]=='O')
                dfs(n-1,j,nums,vis);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(nums[i][j]=='O'&&!vis[i][j])
                    nums[i][j]='X';
            }
        }
    }
};