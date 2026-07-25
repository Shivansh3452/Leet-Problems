class Solution {
public:
    int maxProduct(int n) {
        int maxm=0;
        string s=to_string(n);
        for(int i=0;i<s.size();i++){
            for(int j=i+1;j<s.size();j++){
                maxm=max(maxm,(s[i]-'0')*(s[j]-'0'));
            }
        }
        return maxm;
    }
};