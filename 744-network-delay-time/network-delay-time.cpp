class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int,int>>> adj;
        for(auto& e: times){
            int u=e[0];
            int v=e[1];
            int w=e[2];
            adj[u].push_back({v,w});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> res(n+1,INT_MAX);
        res[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            int d=pq.top().first;
            int adjo=pq.top().second;
            pq.pop();
            for(auto& v:adj[adjo]){
                int dist= v.second;
                int adja=v.first;
                if(d+dist<res[adja]){
                    res[adja]=d+dist;
                    pq.push({d+dist,adja});
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            ans=max(ans,res[i]);
        }
        return ans==INT_MAX?-1:ans;
    }
};