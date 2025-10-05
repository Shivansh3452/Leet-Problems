class Solution {
public:
    bool isPalindrome(string& s,int i,int j){
        int l=i;
        int r=j;
        while(l<r){
            if(s[l]!=s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }

    string longestPalindrome(string s) {
        int n=s.size();
        if(n==0)
            return "";
        int maxlen=0;
        int start=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isPalindrome(s,i,j)){
                    int len=j-i+1;
                    if(len>maxlen){
                        maxlen=len;
                        start=i;
                    }
                    
                }
            }
        }
        return s.substr(start,maxlen);
    }
};