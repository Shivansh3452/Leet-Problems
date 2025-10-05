class Solution {
public:
    int beautySum(string s) {
        int n=s.size();
        int total=0;
        for(int i=0;i<n;i++){
            unordered_map<char,int> mpp;
            for(int j=i;j<n;j++){
                mpp[s[j]]++;

                int maxfreq=INT_MIN;
                int minfreq=INT_MAX;

                for(auto& it:mpp){
                    maxfreq=max(maxfreq,it.second);
                    minfreq=min(minfreq,it.second);
                }
                total+=(maxfreq-minfreq);
            }
        }
        return total;
    }
};