class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int n=s.size();
        int l=0;
        int r=n-1;
        int count=0;
        while(l<r){
            int j=r;
            while(j>l && s[j]!=s[l]){
                j--;
            }
            if(j == l) {
                swap(s[l], s[l + 1]);
                count++;
            }
            else{
                while(j<r){
                    std::swap(s[j],s[j+1]);
                    count++;
                    j++;
                }
                l++;
                r--;
            }
        }
        return count;
    }
};