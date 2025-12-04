// Dekho agar cycle hui graph mein to matlab hai ki eak course krne ke liye tumhe uska prerequisite karna hoga and agar wo prerequisite krna hai tohe course krna pdega jo eak cycle form krega.

// to tumhe kyaa krna hai is topological sort nikalo agar nikalta hai to cycle nhi hai agar nhi nikalta hai to cycle hai bcz topological sort hamesha directed acyclic graph ka nikalta hai


class Solution {
public:
    bool topologicalsortchecker(unordered_map<int,vector<int>> &adj,int n,vector<int> indegree){
        queue<int> q;
        int count=0;
        
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                count++;
                q.push(i);
            }
        }
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int &v:adj[u]){
                indegree[v]--;
                if(indegree[v]==0){
                    count++;
                    q.push(v);
                }
            }
        }
        if(count==n)
                return true;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> adj;
        vector<int> indegree(numCourses,0);

        for(auto& vec:prerequisites){
            int a=vec[0];
            int b=vec[1];

            adj[b].push_back(a);            //populate the map or list
            indegree[a]++;              // uski traf aane wali nodes ka count
        }
        return topologicalsortchecker(adj,numCourses,indegree);
    }
};