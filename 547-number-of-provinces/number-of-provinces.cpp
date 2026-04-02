class Solution {
public:

    void dfs(int idx,vector<bool>& vis,vector<vector<int>>& mat){
        vis[idx]=true;
        for(int i=0;i<mat.size();i++){
            if(!vis[i]&&mat[idx][i])
                dfs(i,vis,mat);
        }
    }
    int findCircleNum(vector<vector<int>>& mat) {
        int n=mat.size();
        vector<bool> vis(n,false);
        int ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis,mat);
                ans++;
            }
        }
        return ans;
    }
};