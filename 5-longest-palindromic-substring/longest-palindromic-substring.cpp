class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        if(n==0)
            return "";
        vector<vector<bool>>t(n,vector<bool>(n));
        int maxLen=1;
        int idx=0;

        for(int i=0;i<n;i++){
            t[i][i]=true;maxLen=1;
        }
        for(int L=2;L<=n;L++){
            for(int i=0;i<n-L+1;i++){
                int j=i+L-1;
                if(s[i]==s[j]&& L==2){
                    t[i][j]=true;
                    if(L>maxLen){  
                        maxLen=2;
                        idx=i;
                    }
                }
                else if(s[i]==s[j]&&t[i+1][j-1]){
                    t[i][j]=true;
                    if(j-i+1>maxLen){
                        maxLen=j-i+1;
                        idx=i;
                    }
                }
            }
        }
        return s.substr(idx,maxLen);
    }
};