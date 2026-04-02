class Solution {
public:

    unordered_map<int,vector<int>> buildgraph(int n,vector<vector<int>> prereq,vector<int>& indeg){
        unordered_map<int,vector<int>> mpp;
        for(auto& e:prereq){
            mpp[e[1]].push_back(e[0]);
            indeg[e[0]]++;
        }
        return mpp;
    }
    bool helper(int n,unordered_map<int,vector<int>>& mpp,vector<int>& indeg,vector<vector<int>> prereq){
        int count=0;
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0){
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
                    count++;
                    q.push(it);
                }
            }

        }
        return count==n;
    }
    bool canFinish(int n, vector<vector<int>>& prereq) {
        vector<int> indeg(n,0);
        unordered_map<int,vector<int>> mpp=buildgraph(n,prereq,indeg);
        return helper(n,mpp,indeg,prereq);
    }
};