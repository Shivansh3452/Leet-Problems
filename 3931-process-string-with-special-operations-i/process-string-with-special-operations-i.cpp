class Solution {
public:
    string processStr(string s) {
        string ans="";
        for(auto&c:s){
            if(c=='*'){
                if(ans=="")
                    continue;
                ans.pop_back();
            }
            else if(c=='#'){
                ans+=ans;
            }
            else if(c=='%'){
                reverse(begin(ans),end(ans));
            }
            else 
                ans+=c;
        } 
        return ans;
    }
};