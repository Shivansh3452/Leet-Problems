// User function Template for C++

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        //bellman ford mein maal V-1 times relaxed hota hai
        //and eak baar aur relax krne ki koshish krte h
        // and agar eak baar aur relaxed ho gya to smjh japo -ve weight cycle 
        // hai and return kar do {-1} 
        // if not then return kar do result
        
        
        // condition for relaxation--
        // if(res[u]!=1e8&&res[u]+w<res[v]){
        //     res[v]=res[u]+w
        // }
        
        vector<int> res(V,1e8);
        res[src]=0;
        for(int count=1;count<=V-1;count++){
            for(auto& e:edges){
                int u=e[0];
                int v=e[1];
                int w=e[2];
                
                if(res[u]+w<res[v]&&res[u]!=1e8){
                    res[v]=res[u]+w;
                }
            }
        }
        for(auto& e:edges){
            int u=e[0];
            int v=e[1];
            int w=e[2];
            
            if(res[u]+w<res[v]&&res[u]!=1e8)
                return {-1};
        }
        return res;
    }
};

























