class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans="";
        for(auto& word:words){
            int wt=0;
            for(int i=0;i<word.size();i++){
                wt+=weights[word[i]-'a'];
            }
            wt%=26;
            ans+=char('z'-wt);
        }
        return ans;
    }
};