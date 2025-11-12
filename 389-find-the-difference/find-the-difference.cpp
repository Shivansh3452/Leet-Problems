class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> mpp;
        for(char&c:t){
            mpp[c]++;
        }
        for(char& c:s){
            mpp[c]--;
        }
        for(auto& it: mpp){
            char ch=it.first;
            if(it.second!=0)
                return ch;
        }
        return ' ';
    }
};