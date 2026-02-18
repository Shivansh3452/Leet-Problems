class Solution {
public:
    vector<vector<int>>t;
    int helper(int i,int j,string& s){
        if(i>j)
            return 0;
        if(t[i][j]!=-1)
            return t[i][j];
        if(s[i]==s[j]){
            if(i==j)
                return t[i][j]=0;
            return t[i][j]=helper(i+1,j-1,s);
        }
        return t[i][j]=1+min(helper(i+1,j,s),helper(i,j-1,s));
    }
    int minInsertions(string s) {
        int n=s.size();
        t.assign(n, vector<int>(n, -1));
        return helper(0,n-1,s);
    }
};