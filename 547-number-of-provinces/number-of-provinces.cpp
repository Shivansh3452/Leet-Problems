class Solution {
public:
    unordered_map<int,vector<int>> buildmap(int n,vector<vector<int>>& isConnected){
        unordered_map<int,vector<int>> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]){
                    ans[i].push_back(j);
                    ans[j].push_back(i);
                }
            }
        }
        return ans;
    }
    void bfs(int u,int n,vector<bool>& vis,unordered_map<int,vector<int>>& mpp){
        vis[u]=true;
        queue<int> q;
        q.push(u);
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(auto& v:mpp[u]){
                if(!vis[v])
                    bfs(v,n,vis,mpp);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        unordered_map<int,vector<int>> mpp=buildmap(n,isConnected);
        vector<bool> vis(n,false);
        int ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                bfs(i,n,vis,mpp);
                ans++;
            }
        }
        return ans;
    }
};