class Solution {
public:

    bool helper(int u,int n,vector<int>& color,vector<vector<int>>& graph){
        queue<int> q;
        q.push(u);
        color[u]=1;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(auto& v:graph[curr]){
                if(color[v]==color[curr])
                    return false;
                else if(color[v]==-1){
                    color[v]=1-color[curr];
                    q.push(v);
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int sze=graph.size();
        vector<int> color(sze,-1);
        for(int i=0;i<sze;i++){
            if(color[i]==-1)
                if(!helper(i,sze,color,graph))
                    return false;
        }
        return true;
    }
};