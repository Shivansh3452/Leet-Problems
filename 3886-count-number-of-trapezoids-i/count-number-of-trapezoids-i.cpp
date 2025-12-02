class Solution {
public:

    static const long long mod = 1000000007;
    long long countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int,int> mpp;
        for(auto& point:points){
            int y=point[1];
            mpp[y]++;
        }
        long long res=0;
        long long prevHorizontalLine=0;
        for(auto& it: mpp){
            int count=it.second;
            long long horizontalLine=(long long )count*(count-1)/2;
            res+=horizontalLine*prevHorizontalLine% mod;
            prevHorizontalLine+=horizontalLine% mod;
        }
        return (res%mod+mod)%mod;
    }
};