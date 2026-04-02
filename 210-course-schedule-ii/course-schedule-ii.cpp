class Solution {
public:
    unordered_map<int,vector<int>> buildgraph(int n,vector<int>& indeg,vector<vector<int>>& prereq){
        unordered_map<int,vector<int>> mpp;
        for(auto& e:prereq){
            mpp[e[1]].push_back(e[0]);
            indeg[e[0]]++;
        }
        return mpp;
    }
    vector<int> topocheck(int n,unordered_map<int,vector<int>>& mpp,vector<int>& indeg){
        vector<int> ans;
        int count =0;
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                ans.push_back(i);
                count++;
                q.push(i);
            }
        }
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(auto& it:mpp[curr]){
                indeg[it]--;

                if(indeg[it]==0){
                    ans.push_back(it);
                    count++;
                    q.push(it);
                }
            }
        }
        if(count==n)
            return ans;
        return {};
    }
    vector<int> findOrder(int n, vector<vector<int>>& prereq) {
        vector<int> indeg(n,0);
        unordered_map<int,vector<int>> mpp=buildgraph(n,indeg,prereq);
        vector<int> ans=topocheck(n,mpp,indeg);
        return ans;
    }
};