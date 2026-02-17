class Solution {
public:
    int t[501][501];
    int helper(int i,int j,string& s1,string& s2,int m,int n){
        if(i==m)
            return n-j;
        if(j==n)    
            return m-i;
        if(t[i][j]!=-1)
            return t[i][j];
        if(s1[i]==s2[j])
            return helper(i+1,j+1,s1,s2,m,n);
        else{
            int inset=1+helper(i,j+1,s1,s2,m,n);
            int delet=1+helper(i+1,j,s1,s2,m,n);
            int leplace=1+helper(i+1,j+1,s1,s2,m,n);
            return t[i][j]=min({inset,delet,leplace});
        }
        return -1;
    }
    int minDistance(string s1, string s2) {
        int m=s1.size();
        int n=s2.size();
        memset(t,-1,sizeof(t));
        return helper(0,0,s1,s2,m,n);
    }
};