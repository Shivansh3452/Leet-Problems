class Solution {
public:

    bool isPalindrome(int i,int j,string& s){
        if(i>j)
            return true;
        if(s[i]==s[j])
            return isPalindrome(i+1,j-1,s);
        return false;
    }
    int countSubstrings(string s) {
        int n=s.size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isPalindrome(i,j,s))
                    count++;
            }
        }
        return count;
    }
};