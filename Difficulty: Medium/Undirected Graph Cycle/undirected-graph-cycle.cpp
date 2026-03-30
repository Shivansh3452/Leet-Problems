class Solution {
  public:
  
    vector<vector<int>> grapher(int V,vector<vector<int>>& edges){
        vector<vector<int>> adj(V);
        for(auto& e:edges){
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return adj;
    }
    
    bool isCycleDFS(vector<vector<int>> &adj,int u,vector<bool> &vis,int parent){
        vis[u]=true;
        for(int &v:adj[u]){
            if(v==parent)
                continue;
            if(vis[v])
               return true;
          if(isCycleDFS(adj,v,vis,u))
            return true;
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj=grapher(V,edges);
        vector<bool> vis(V,false);
        for(int i=0;i<V;i++){
            if(!vis[i]&&isCycleDFS(adj,i,vis,-1))
                return true;
        }
        return false;
    }
};