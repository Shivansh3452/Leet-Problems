class Solution {
  public:
  
    void DFS(vector<vector<int>> &adj,int u,vector<bool> &visited,vector<int> &res){
        if(visited[u]==true)
            return;
        visited[u]=true;
        res.push_back(u);
        for(int &v:adj[u]){
            if(!visited[v]){
                DFS(adj,v,visited,res);
            }
        }
    }
  
    vector<int> dfs(vector<vector<int>>& adj) {
        unordered_map<int,vector<int>> mpp;
        int V=adj.size();
        
        vector<int> res;
        vector<bool> visited(V,false);
        
        DFS(adj,0,visited,res);
        
        return res;
    }
};