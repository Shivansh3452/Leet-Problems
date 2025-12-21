// class Solution {
// public:

//     bool allEqual(vector<int>& cost){
//         int n=cost.size();
//         for(int i=1;i<n;i++){
//             if(cost[i]!=cost[0])
//                 return false;
//         }
//         return true;
//     }
//     bool allSame(string &s){
//         char c=s[0];
//         for(int i=1;i<s.size();i++){
//             if(c!=s[i])
//                 return false;
//         }
//         return true;
//     }
//     long long minCost(string s, vector<int>& cost) {
//         long long n=s.size();
//         unordered_map<char,long long> mpp(n);
//         for(int i=0;i<n;i++){
//             mpp[s[i]]+=cost[i];
//         }
//         long long maxm=LLONG_MIN;
//         for(auto& c:mpp){
//             maxm=max(maxm,c.second);
//         }
//         long long total=0;
//         for(auto &c:mpp){
//             if(c.second!=maxm){
//                 total+=c.second;
//             }
//         }
//         if(allEqual(cost) && !allSame(s))
//             return cost[n-1];
//         return total;
//     }
// };

class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        long long n=s.size();
        unordered_map<char,long long>mpp(n);
        for(int i=0;i<n;i++){
            mpp[s[i]]+=cost[i];
        }
        long long maxm=LLONG_MIN;
        for(auto& c :mpp){
            maxm=max(maxm,c.second);
        }
        long long total=0;
        bool skippedMax=false;
        for(auto& c:mpp){
            if(c.second==maxm&&!skippedMax){
                skippedMax = true;      // Keep one character with max cost
                continue;
            }
            total+=c.second;
        }
        
        return total;
    }
};