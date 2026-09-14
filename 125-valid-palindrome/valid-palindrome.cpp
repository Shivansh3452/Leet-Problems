class Solution {
public:
    string filter(string& s){
        string ans="";
        for(auto& it: s){
            it=tolower(it);
            if(isalnum(it))
                ans+=it;
        }
        return ans;
    }
    bool helper(string s){
        int i=0,j=s.size()-1;
        while(i<j){
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    bool isPalindrome(string s) {
        s=filter(s);
        cout<<s;
        return helper(s);
    }
};