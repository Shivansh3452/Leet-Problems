class Solution {
public:
    int t[501][501];
    int minDistance(string s1, string s2) {
        int m=s1.size();
        int n=s2.size();
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i==0||j==0)
                    t[i][j]=i+j;
                else if(s1[i-1]==s2[j-1])
                    t[i][j]=t[i-1][j-1];
                else
                    t[i][j]=1+min({t[i-1][j],t[i][j-1],t[i-1][j-1]});
            }
        }
        return t[m][n];
    }
};