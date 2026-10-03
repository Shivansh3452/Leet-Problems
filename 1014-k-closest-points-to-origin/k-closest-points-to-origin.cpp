class Solution {
public:
    int helper(int x,int y){
        return ((x*x)+(y*y));
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> mpp;
        for(auto& it: points){
            int x=it[0];
            int y=it[1];
            int dist=helper(x,y);
            mpp.push_back({dist, x, y});
        }
        sort(begin(mpp),end(mpp),[&](vector<int>& a,vector<int>& b){
            return a[0]<b[0];
        });
        vector<vector<int>> ans;
        for(auto& it:mpp){
            if(k==0)
                return ans;
            ans.push_back({it[1],it[2]});
            k--;
        }
        return ans;
    }
};