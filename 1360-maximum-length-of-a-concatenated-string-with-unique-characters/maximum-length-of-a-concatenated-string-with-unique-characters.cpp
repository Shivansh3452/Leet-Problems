class Solution {
public:

    void solve(int idx,int temp,int& res,vector<int>& uniquechar){
        res=max(res,__builtin_popcount(temp));
        for(int i=idx;i<uniquechar.size();i++){
            if((temp& uniquechar[i])==0){
                solve(i+1,temp|uniquechar[i],res,uniquechar);
            }
        }
    }

    int maxLength(vector<string>& arr) {
        vector<int> uniquechar;
        for(string& s:arr){
            unordered_set<char> st(begin(s),end(s));
            if(st.size()!=s.length())
                continue;
            int val=0;
            for(char& ch:s){
                val=(val|(1<<(ch-'a')));
            }
            uniquechar.push_back(val);
        }
        int res=0;
        int temp=0;
        solve(0,temp,res,uniquechar);
        return res;
    }
};