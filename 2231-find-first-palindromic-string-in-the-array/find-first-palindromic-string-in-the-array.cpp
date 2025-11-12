class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(auto& s:words){
            string rev_s=s;
            reverse(rev_s.begin(),rev_s.end());
            if(rev_s==s){
                return s;
            }
        }
        return "";
    }
};