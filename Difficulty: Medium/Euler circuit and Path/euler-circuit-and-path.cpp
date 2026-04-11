class Solution {
  public:
    void dfs(int nonZeroVertex,vector<bool>& vis,int V,vector<int> adj[]){
        vis[nonZeroVertex]=true;
        for(auto& neigh:adj[nonZeroVertex]){
            if(!vis[neigh])
                dfs(neigh,vis,V,adj);
        }
    }
    bool isConnected(int V,vector<int> adj[]){
        int nonZeroVertex=-1;
        for(int i=0;i<V;i++){
            if(adj[i].size()!=0){
                nonZeroVertex=i;
                break;
            }
        }
        vector<bool> vis(V,false);
        dfs(nonZeroVertex,vis,V,adj);
        for(int i=0;i<V;i++){
            if(!vis[i]&&adj[i].size()>0)
                return false;
        }
        return true;
    }
    int isEulerCircuit(int V, vector<int> adj[]) {
        if(!isConnected(V,adj))
            return 0;
        int odddegvertex=0;
        for(int i=0;i<V;i++){
            if(adj[i].size()%2!=0)
                odddegvertex++;
        }
        if(odddegvertex==2)
            return 1;
        if(odddegvertex>2)
            return 0;
        return 2;
    }
};