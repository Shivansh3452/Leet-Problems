class Solution {
  public:
  
    void DFS(vector<vector<int>> &adj,int u,vector<bool> &visited,stack<int> &s){
        visited[u]=true;
        for(auto& v:adj[u]){
            if(!visited[v]){
                DFS(adj,v,visited,s);
            }
        }
        s.push(u);
    }
  
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for(auto& e: edges){
            int u=e[0];
            int v=e[1];
            
            adj[u].push_back(v);
        }
        vector<bool> visited(V,false);
        vector<int> res;
        stack<int> s;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                DFS(adj,i,visited,s);
            }
        }
        while(!s.empty()){
            res.push_back(s.top());
            s.pop();
        }
        return res; 
        
    }
};