class Solution {
public:
    typedef pair<int,pair<int,int>> P;
    bool isSafe(int x,int y,int m,int n){
        return x>=0&&y>=0&&x<m&&y<n;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        if(m==1&&n==1)
            return 0;
        vector<pair<int,int>> moves={{-1,0},{0,-1},{1,0},{0,1}};
        priority_queue<P,vector<P>,greater<P>> pq;
        vector<vector<int>> res(m,vector<int>(n,INT_MAX));
        res[0][0]=0;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            int diff=pq.top().first;
            auto cord=pq.top().second;
            pq.pop();
            int x=cord.first;
            int y=cord.second;

            for(auto& move:moves){
                int x_=x+move.first;
                int y_=y+move.second;

                if(isSafe(x_,y_,m,n)){
                    int absDiff=abs(heights[x][y]-heights[x_][y_]);
                    int maxDiff=max(diff,absDiff);

                    if(res[x_][y_]>maxDiff){
                        res[x_][y_]=maxDiff;
                        pq.push({maxDiff,{x_,y_}});
                    }
                }
            }
        }
        return res[m-1][n-1];
    }
};