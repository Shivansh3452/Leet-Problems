
//              KAHN ALHORITHM


class Solution {
  public:
    vector<int> topoSort(int N, vector<vector<int>>& edges) {
        vector<vector<int>> adj(N);
        vector<int> indegree(N,0);
        for(auto& edge: edges){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        queue<int> q;
        for(int i=0;i<N;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> result;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            result.push_back(u);
            
            for(auto& v:adj[u]){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                }
            }
        }
        return result;
    }
};