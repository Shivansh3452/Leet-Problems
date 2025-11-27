class Solution {
  public:
  
    bool isCycle(vector<vector<int>> &adj,int u,vector<bool> &visited,vector<bool> &currRev){
        visited[u]=true;
        currRev[u]=true;
        for(int &v:adj[u]){
            if(!visited[v] && isCycle(adj,v,visited,currRev)){
                return true;
            }
            else if(currRev[v]==true){
                return true;
            }
        }
        currRev[u]=false;
        return false;
    }
  
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);
        for(auto &e: edges){
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
        }
        vector<bool> visited(V,false);
        vector<bool> currRev(V,false);
        
        for(int i=0;i<V;i++){
            if(!visited[i]&& isCycle(adj,i,visited,currRev)){
                return true;
            }
        }
        return false;
    }
};