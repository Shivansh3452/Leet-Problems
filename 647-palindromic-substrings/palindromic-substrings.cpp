class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        vector<vector<bool>> t(n,vector<bool>(n,false));
        int count=0;
//state=t[i][j]=true:s[i:j] is a palindrome substring where i and j are inclusive
        for(int L=1;L<=n;L++){
            for(int i=0;i+L<=n;i++){
                int j=i+L-1;
                if(L==1)    //size is 1;
                    t[i][j]=true;
                else if(L==2)  //size is 2
                    t[i][j]=(s[i]==s[j]);
                else 
                    t[i][j]=(s[i]==s[j]&&t[i+1][j-1]);
                if(t[i][j])
                    count++;
                }
        }
        return count;
    }
};