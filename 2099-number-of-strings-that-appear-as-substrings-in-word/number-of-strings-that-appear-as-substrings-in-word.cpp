class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int ans=0;
        for(auto& it: patterns){
            int sze=it.size();
            for(int i=0;i<word.size();i++){
                if(word.substr(i,sze)==it){
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};