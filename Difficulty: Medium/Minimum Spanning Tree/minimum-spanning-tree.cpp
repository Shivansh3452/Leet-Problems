class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<vector<pair<int,int>>> adj(V);
        for(auto& e:edges){
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],e[2]});
        }
        vector<bool> inMst(V,false);
        pq.push({0,0});
        int wt=0;
        while(!pq.empty()){
            auto [weight,node]=pq.top();
            pq.pop();
            if(inMst[node])
                continue;
            inMst[node]=true;
            wt+=weight;
            
            for(auto& neighbor: adj[node]){
                int next=neighbor.first;
                int dist=neighbor.second;
                if(!inMst[next]){
                    pq.push({dist,next});
                }
            }
        }
        return wt;
    }
};