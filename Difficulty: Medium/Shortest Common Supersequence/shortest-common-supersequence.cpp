class Solution {
  public:
  
  int t[1001][1001];
  
    int helper(string& s1,string& s2,int m,int n){
        if(m==0)
            return n;
        else if(n==0)
            return m;
        if(t[m][n]!=-1)
            return t[m][n];
        if(s1[m-1]==s2[n-1])
            return t[m][n]=1+helper(s1,s2,m-1,n-1);
        else
            return t[m][n]=1+min(helper(s1,s2,m-1,n),helper(s1,s2,m,n-1));
    }
    int minSuperSeq(string &s1, string &s2) {
        int m=s1.size();
        int n=s2.size();
        memset(t,-1,sizeof(t));
        return helper(s1,s2,m,n);
    }
};