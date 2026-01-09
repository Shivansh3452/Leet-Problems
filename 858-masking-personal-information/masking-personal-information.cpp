class Solution {
public:
    string maskPII(string s) {
        if (s.find('@')!=string::npos) {       // mtlb email hai
            string ans="";
            ans+=tolower(s[0]);     // phla character added
            int ast=5;
            while(ast--) {           // ***** add kro
                ans+='*';
            }
            // last character before '@'
            for (int i=1;i<s.size();i++) {
                if (s[i] == '@') {
                    ans += tolower(s[i - 1]);
                    break;
                }
            }
            // @ jod do
            int cnt=0;
            for(char &c:s) {
                if(c=='@')
                    break;
                cnt++;
            }
            for(int i=cnt;i<s.size();i++) {
                ans+=tolower(s[i]);
            }
            return ans;
        }

        // ab to phone number hi hoga
        string digits="";
        for (char c:s) {
            if(isdigit(c))
                digits+=c;        // saare digits nikal liye
        }
        string numans="";
        int country=digits.size() - 10;   // country code

        if(country>0){
            numans+='+';
            while(country--){
                numans+='*';
            }
            numans+='-';
        }
        numans+="***-***-";
        numans+=digits.substr(digits.size()-4);
        return numans;
    }
};
