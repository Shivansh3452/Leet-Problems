class Solution {
public:
    int t[1001][1001];
    bool helper(int i,int j,string s){
        if(i>j)
            return true;
        if(t[i][j]!=-1)
            return t[i][j];
        if(s[i]==s[j])
            return t[i][j]=helper(i+1,j-1,s);
        return t[i][j]=false;
    }
    int countSubstrings(string s) {
        memset(t,-1,sizeof(t));
        int count=0;
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                if(helper(i,j,s))
                    count++;
            }
        }
        return count;
    }
};