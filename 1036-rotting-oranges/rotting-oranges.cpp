class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid){
        int m=grid.size();
        int n=grid[0].size();
        int count=0;
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)
                    count++;
                else if(grid[i][j]==2)
                    q.push({i,j});
            }
        }
        int directions[5]={-1,0,1,0,-1};
        for(int min=1;count>0&&!q.empty();min++){
            int size=q.size();
            for(int k=0;k<size;k++){
                auto [i,j]=q.front();
                q.pop();
                for(int dir=0;dir<4;dir++){
                    int nextRow=i+directions[dir];
                    int nextCol=j+directions[dir+1];
                    if(nextRow>=0&&nextRow<m&&nextCol>=0&&nextCol<n&&grid[nextRow][nextCol]==1){
                        grid[nextRow][nextCol]=2;
                        q.push({nextRow,nextCol});
                        count--;
                        if(count==0)
                            return min;
                    }
                }
            }
        }
        return count>0?-1:0;
    }
};