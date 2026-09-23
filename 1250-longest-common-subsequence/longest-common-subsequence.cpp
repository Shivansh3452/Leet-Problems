class Solution {
public:
    int t[1001][1001];
    int helper(int i,int j,int m,int n,string& s1, string& s2){
        if(i>=m||j>=n||i<0||j<0)
            return 0;
        if(t[i][j]!=-1)
            return t[i][j];
        if(s1[i]==s2[j])
            return t[i][j]=1+helper(i+1,j+1,m,n,s1,s2);
        return t[i][j]=max(helper(i+1,j,m,n,s1,s2),helper(i,j+1,m,n,s1,s2));
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(t,-1,sizeof(t));
        int m=text1.size();
        int n=text2.size();
        return helper(0,0,m,n,text1,text2);
    }
};