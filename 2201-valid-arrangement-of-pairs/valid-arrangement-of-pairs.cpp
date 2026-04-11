class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int,int> outdeg,indeg;
        unordered_map<int,vector<int>> adj;
        for(auto& e: pairs){
            adj[e[0]].push_back(e[1]);      //e[0]------>e[1]
            outdeg[e[0]]++;
            indeg[e[1]]++;
        }
        //find the first maal
        int start=pairs[0][0];
        for(auto& it: adj){
            int node=it.first;
            if(outdeg[node]-indeg[node]==1){
                start=node;
                break;
            }
        }
        vector<int> eulerPath;
        stack<int> st;
        st.push(start);
        while(!st.empty()){
            int curr=st.top();
            if(!adj[curr].empty()){
                int ngbr=adj[curr].back();
                adj[curr].pop_back();
                st.push(ngbr);
            }
            else{
                eulerPath.push_back(curr);
                st.pop();
            }
        }
        reverse(begin(eulerPath),end(eulerPath));
        vector<vector<int>> ans;
        for(int i=0;i<eulerPath.size()-1;i++){
            ans.push_back({eulerPath[i],eulerPath[i+1]});
        }
        return ans;
    }
};