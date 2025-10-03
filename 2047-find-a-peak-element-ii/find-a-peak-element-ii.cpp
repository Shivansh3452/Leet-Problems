class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m=mat.size()-1;
        int n=mat[0].size()-1;
        while(m>=0 && m<mat.size() && n>=0 && n<mat[0].size()){
            int curr_peak=mat[m][n];
            if((m+1>=mat.size() || curr_peak>mat[m+1][n]) && 
               (n+1>=mat[0].size() || curr_peak>mat[m][n+1]) && 
               (n-1<0 || curr_peak>mat[m][n-1]) && 
               (m-1<0 || curr_peak>mat[m-1][n])){
                return {m,n};
            }
            else{
                if(n+1<mat[0].size() && mat[m][n+1]>curr_peak){
                    n=n+1;
                }
                else if(m+1<mat.size() && mat[m+1][n]>curr_peak){
                    m=m+1;
                }
                else if(n-1>=0 && mat[m][n-1]>curr_peak){
                    n=n-1;
                }
                else if(m-1>=0 && mat[m-1][n]>curr_peak){
                    m=m-1;
                }
            }
        }
        return {};
    }
};