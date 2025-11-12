class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(auto& s:words){
            if(s.size()==1)
                return s;
            int i=0;
            int j=s.size()-1;
            while(i<j){
                if(s[i]!=s[j]){
                    break;
                }
                i++;
                j--;
                if(i>=j)
                    return s;
            }
        }
        return "";
    }
};