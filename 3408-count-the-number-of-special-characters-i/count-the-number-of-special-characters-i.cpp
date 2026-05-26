class Solution {
public:
    int numberOfSpecialChars(string word) {
        int ans=0;
        unordered_map<char,int> mpp;
        for(auto& it: word){
            mpp[it]++;
        }
        for(char i='a';i<='z';i++){
            if(mpp[i]>=1&&mpp[toupper(i)]>=1)
                ans++;
        }
        return ans;
    }
};