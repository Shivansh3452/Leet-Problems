class Solution {
  public:
  
    vector<vector<int>> buildgraph(int V,vector<vector<int>>& edges){
        vector<vector<int>> adj(V);
        for(auto& e:edges){
            adj[e[0]].push_back(e[1]);
        }
        return adj;
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj=buildgraph(V,edges);
        vector<int>indeg(V,0);
        for(auto& u:adj){
            for(auto& v:u){
                indeg[v]++;
            }
        }
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indeg[i]==0)
                q.push(i);
        }
        vector<int> res;
        while(!q.empty()){
            int u=q.front();
            res.push_back(u);
            q.pop();
            
            for(auto& v:adj[u]){
                indeg[v]--;
                if(indeg[v]==0)
                q.push(v);
            }
            
        }
        return res;
    }
};