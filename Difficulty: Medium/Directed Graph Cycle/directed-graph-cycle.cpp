class Solution {
  public:
  
    vector<vector<int>> buildgraph(int V,vector<vector<int>> &edges){
        vector<vector<int>> adj(V);
        for(auto& e: edges){
            adj[e[0]].push_back(e[1]);
        }
        return adj;
    }
    bool isCycle(vector<vector<int>>& adj,int u,vector<bool>& vis,vector<bool>& inRec){
        vis[u]=true;
        inRec[u]=true;
        for(auto& v:adj[u]){
            if(!vis[v]&&isCycle(adj,v,vis,inRec))
                return true;
            else if(inRec[v]==true)
                return true;
        }
        inRec[u]=false;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj=buildgraph(V,edges);
        vector<bool>vis(V);
        vector<bool>inRec(V);
        for(int i=0;i<V;i++){
            if(!vis[i]&&isCycle(adj,i,vis,inRec))
                return true;
        }
        return false;
    }
};