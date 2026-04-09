class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(V);
        for(auto& e:edges){
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],e[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<bool> inMST(V,false);
        pq.push({0,0});
        int sum=0;
        while(!pq.empty()){
            auto tp=pq.top();
            pq.pop();
            int wt=tp.first;
            int node=tp.second;
            
            if(inMST[node])
                continue;
            inMST[node]=true;
            sum+=wt;
            for(auto& neigh:adj[node]){
                int neighbor=neigh.first;
                int neigh_wt=neigh.second;
                if(!inMST[neighbor]){
                    pq.push({neigh_wt,neighbor});
                }
            }
        }
        return sum;
    }
};