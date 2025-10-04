class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        stack<char> st;
        for (auto& c : s) {
            if (c == '(') {
                if (!st.empty()) {
                    ans += c;
                }
            st.push(c);
            }
            else if (c == ')') {
                st.pop();
                if (!st.empty()) {
                    ans += c;
                }
            }
        }
        return ans;
    }
};