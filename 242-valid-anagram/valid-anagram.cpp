class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> mpp1;
        unordered_map<char,int> mpp2;
        for(auto& it:s)
            mpp1[it]++;
        for(auto& it:t)
            mpp2[it]++;
        // for(auto& it: mpp){
        //     if(it.second%2!=0)
        //         return false;
        // }
        // return true;
        return mpp1==mpp2;
    }
};