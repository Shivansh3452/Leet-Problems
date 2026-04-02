class Solution {
  public:
  
    vector<vector<int>> buildgraph(int V,vector<vector<int>> &edges){
        vector<vector<int>> adj(V);
        for(auto& e:edges)
            adj[e[0]].push_back(e[1]);
        return adj;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj=buildgraph(V,edges);
        vector<int> indeg(V);
        for(auto& u:adj){
            for(auto& v:u)
                indeg[v]++;
        }
        int count=0;
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indeg[i]==0){
                q.push(i);
                count++;
            }
        }
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(auto& v:adj[u]){
                indeg[v]--;
                
                if(indeg[v]==0){
                    q.push(v);
                    count++;
                }
            }
        }
        return !(count==V);
    }
};