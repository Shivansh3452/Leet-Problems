class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count=0;
        int m=grid.size();
        int n=grid[0].size();
        int l1=0;
        int r2=n-1;
        while(l1<m&&r2>=0){
            if(grid[l1][r2]<0){
                count+=(m-l1);
                r2--;
            }
            else{
                l1++;
            }
        }
        return count;
    }
};
