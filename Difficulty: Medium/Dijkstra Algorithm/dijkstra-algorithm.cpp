class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        //by set
        
        vector<vector<pair<int,int>>> adj(V);
        for(auto& e:edges){
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],e[2]});
        }
        set<pair<int,int>> st;      //ordered set
        vector<int> res(V,INT_MAX);
        res[src]=0;
        st.insert({0,src});
        
        while(!st.empty()){
            auto &it=*st.begin();
            int d=it.first;
            int adja=it.second;
            st.erase(it);
            
            for(auto& vec:adj[adja]){
                int adjNode=vec.first;
                int dist=vec.second;
                if(d+dist<res[adjNode]){
                    if(res[adjNode]!=INT_MAX){
                        st.erase({res[adjNode],adjNode});
                    }
                    res[adjNode]=d+dist;
                    st.insert({d+dist,adjNode});
                }
            }
        }
        return res;
    }
};