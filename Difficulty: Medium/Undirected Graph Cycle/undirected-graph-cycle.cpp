class Solution {
  public:
  
    vector<vector<int>> grapher(int V,vector<vector<int>>& edges){
        vector<vector<int>> adj(V);
        for(auto& e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        return adj;
    }
    
    bool isCycleDFS(vector<vector<int>>& adj,int u,vector<bool>& vis,int parent){
        vis[u]=true;
        for(auto& v:adj[u]){
            if(v==parent)
                continue;
            if(vis[v]==true)
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