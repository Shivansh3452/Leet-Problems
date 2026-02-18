class Solution {
public:
    int t[1001][1001];
    int helper(int i,int j,string& s){
        if(i>j)
            return 0;
        if(i==j)
            return 1;
        if(t[i][j]!=-1)
            return t[i][j];
        if(s[i]==s[j])
            return t[i][j]=2+helper(i+1,j-1,s);
        else
            return t[i][j]=max(helper(i+1,j,s),helper(i,j-1,s));
    }
    int longestPalindromeSubseq(string s) {
        int n=s.length();
        memset(t,-1,sizeof(t));
        if(n==1)
            return 1;
        return helper(0,n-1,s);
    }
};