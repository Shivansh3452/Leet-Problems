class Solution {
  public:
  
    void dfs(vector<int> adj[],int u,vector<bool>& vis){
        vis[u]=true;
        for(int neighbor:adj[u]){
            if(vis[neighbor]==false)
                dfs(adj,neighbor,vis);
        }
    }
    bool isConnected(int V,vector<int> adj[]){
        vector<bool> vis(V,false);
        int nonzeroconnected=-1;
        for(int i=0;i<V;i++){
            if(adj[i].size()>0){
                nonzeroconnected=i;
                break;
            }
        }
        if(nonzeroconnected==-1)
            return true;
        dfs(adj,nonzeroconnected,vis);
        for(int i=0;i<V;i++){
            if(vis[i]==false&&adj[i].size()>0)
                return false;
        }
        return true;
    }
    int isEulerCircuit(int V, vector<int> adj[]) {
        if(isConnected(V,adj)==false)
            return 0;
        int oddDegreeCount=0;
        for(int i=0;i<V;i++){
            if(adj[i].size()%2!=0)
                oddDegreeCount++;
        }
        if(oddDegreeCount>2)
            return 0;
        if(oddDegreeCount==2)
            return 1;
        return 2;
    }
};