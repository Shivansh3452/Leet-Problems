class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> arr(n,vector<int> (n,0));
        for(int i=0;i<queries.size();i++){
            int r1=queries[i][0];
            int c1=queries[i][1];
            int r2=queries[i][2];
            int c2=queries[i][3];

            for(int j=r1;j<=r2;j++){
                arr[j][c1]++;
                if((c2+1)<n){
                    arr[j][c2+1]--;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=1;j<n;j++){
                arr[i][j]+=arr[i][j-1];
            }
        }
        return arr;
    }
};