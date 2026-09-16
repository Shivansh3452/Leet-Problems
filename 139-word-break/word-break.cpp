class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        vector<bool> t(n+1,false);
        t[0]=true;
        unordered_set<string>wordSet(begin(wordDict),end(wordDict));
        for(int i=1;i<=n;i++){
            for(int j=0;j<i;j++){
                if(t[j]&&wordSet.count(s.substr(j,i-j))){
                    t[i]=true;
                    break;
                }
            }
        }
        return t[n];
    }
};