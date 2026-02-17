class Solution {
public:
    int t[501][501];
    int helper(int m,int n,string& s1,string& s2){
        if(m==0||n==0)
            return m+n;
        if(t[m][n]!=-1)
            return t[m][n];
        if(s1[m-1]==s2[n-1])
            return helper(m-1,n-1,s1,s2);
        else{
            int inset=1+helper(m,n-1,s1,s2);
            int delet=1+helper(m-1,n,s1,s2);
            int leplace=1+helper(m-1,n-1,s1,s2);
            return t[m][n]=min({inset,delet,leplace});
        }
        return -1;
    }
    int minDistance(string s1, string s2) {
        int m=s1.size();
        int n=s2.size();
        memset(t,-1,sizeof(t));
        return helper(m,n,s1,s2);
    }
};