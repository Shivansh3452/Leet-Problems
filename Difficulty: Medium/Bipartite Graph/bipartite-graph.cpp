class Solution {
  public:
    unordered_map<int,vector<int>> buildmap(int V,vector<vector<int>> &edges){
        unordered_map<int,vector<int>> adj;
        for(auto& e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        return adj;
    }
    
    bool DFS(int u,vector<int>& color,unordered_map<int,vector<int>>& adj,int currColor){
        color[u]=currColor;
        for(auto& v:adj[u]){
            if(color[v]==-1){
                if(DFS(v,color,adj,1-currColor)==false)
                    return false;
            }
            else if(color[v]==currColor)
                return false;
        }
        return true;
    }
    
    bool isBipartite(int V, vector<vector<int>> &edges) {
        unordered_map<int,vector<int>> adj=buildmap(V,edges);
        vector<int> color(V,-1);
        for(int i=0;i<V;i++){
            if(color[i]==-1)
                if(DFS(i,color,adj,1)==false)
                    return false;
        }
        return true;
    }
};