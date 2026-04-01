class Solution {
  public:
  
    vector<vector<int>> buildgraph(int V,vector<vector<int>>& edges){
        vector<vector<int>> adj(V);
        for(auto& e: edges){
            adj[e[0]].push_back(e[1]);
        }
        return adj;
    }
    
    void DFS(vector<vector<int>>& adj,int u,int V,vector<bool>& vis,stack<int>& st){
        vis[u]=true;
        for(auto& v:adj[u]){
            if(!vis[v])
                DFS(adj,v,V,vis,st);
        }
        st.push(u);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj=buildgraph(V,edges);
        vector<bool> vis(V,false);
        stack<int> st;
        for(int i=0;i<V;i++){
            if(!vis[i])
                DFS(adj,i,V,vis,st);
        }
        vector<int> res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        
        return res;
    }
};