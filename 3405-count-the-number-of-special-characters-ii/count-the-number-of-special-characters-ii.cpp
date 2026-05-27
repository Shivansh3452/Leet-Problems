class Solution {
public:
    int numberOfSpecialChars(string word) {
        int ans=0;
        unordered_map<char,pair<int,int>> mpp;  //first is freq and second is pos
        for(int i=0;i<word.size();i++){
            if(isupper(word[i])&&mpp[word[i]].first==0)//uppercase→firstoccurrence
                mpp[word[i]].second=i;  
            if(islower(word[i]))    //lowercase→lastoccurrence
                mpp[word[i]].second=i;
            mpp[word[i]].first++;
        }
        for(auto& it: mpp){
            if(islower(it.first)&&mpp.count(toupper(it.first))&&it.second.second
            <mpp[toupper(it.first)].second)
                ans++;
}
        return ans;
    }
};