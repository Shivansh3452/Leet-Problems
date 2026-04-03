class Solution {
public:

    bool helper(int u,unordered_map<int,vector<int>>& mpp,vector<bool>& vis,vector<bool> inrec){
        vis[u]=true;
        inrec[u]=true;

        for(auto& v:mpp[u]){
            if(!vis[v]&&helper(v,mpp,vis,inrec))
                return true;
            else if(inrec[v])
                return true;
        }
        inrec[u]=true;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& prereq) {
        vector<bool> vis(n,false);
        vector<bool> inrec(n,false);

        unordered_map<int,vector<int>> adj;
        for(auto& e:prereq){
            adj[e[0]].push_back(e[1]);
        }
        for(int i=0;i<n;i++){
            if(!vis[i]&& helper(i,adj,vis,inrec)){
                return false;
            }
        }
        return true;
    }
};