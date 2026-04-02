class Solution {
public:
    unordered_map<int,vector<int>> buildmap(vector<vector<int>>& prereq){
        unordered_map<int,vector<int>> mpp;
        for(auto& it:prereq){
            mpp[it[1]].push_back(it[0]);
        }
        return mpp;
    }
    bool isCycle(int i,vector<bool>& rec,vector<bool>& vis,unordered_map<int,vector<int>>& mpp){
        vis[i]=true;
        rec[i]=true;
        for(auto& v:mpp[i]){
            if(!vis[v]&&isCycle(v,rec,vis,mpp))
                return true;
            else if(rec[v])
                return true;
        }
        rec[i]=false;
        return false;
        
    }
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<bool> vis(n,false);
        vector<bool> rec(n,false);
        unordered_map<int,vector<int>> mpp=buildmap(prerequisites);
        for(int i=0;i<n;i++){
            if(!vis[i]&&isCycle(i,rec,vis,mpp))
                return false;
        }
        return true;
    }
};