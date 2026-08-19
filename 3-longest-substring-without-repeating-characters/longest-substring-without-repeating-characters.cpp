class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length()==0||s.length()==1)
            return s.length();
        unordered_set<char>st;
        int ans=0;
        int l=0;
        for(int i=0;i<s.size();){
            while(st.contains(s[i])){
                st.erase(s[l]);
                l++;
            }
            st.insert(s[i]);
            if(ans<st.size()){
                ans=st.size();
            }
            i++;
        }
        return ans;
    }
};