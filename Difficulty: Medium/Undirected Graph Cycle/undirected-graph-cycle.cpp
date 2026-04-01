class Solution {
  public:
  
    vector<vector<int>> buildadj(int V,vector<vector<int>>& edges){
        vector<vector<int>> adj(V);
        for(auto& e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        return adj;
    }
    bool isCycleBFS(vector<vector<int>>& adj,int u,vector<bool>& vis){
        queue<pair<int,int>> q;
        q.push({u,-1});
        vis[u]=true;
        while(!q.empty()){
            pair<int,int> p=q.front();
            q.pop();
            int src=p.first;
            int parent=p.second;
            for(int &v:adj[src]){
                if(!vis[v]){
                    vis[v]=true;
                    q.push({v,src});
                }
                else if(v!=parent)
                    return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj=buildadj(V,edges);
        vector<bool> vis(V,false);
        for(int i=0;i<V;i++){
            if(!vis[i]&&isCycleBFS(adj,i,vis))
                return true;
        }
        return false;
    }    
};