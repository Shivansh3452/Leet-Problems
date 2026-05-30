class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res(k);
        unordered_map<int,int> mpp;
        for(auto& it: nums){
            mpp[it]++;
        }
        vector<pair<int,int>> freq(mpp.begin(),mpp.end());
        sort(freq.begin(),freq.end(),[&](const pair<int,int>& a,const pair<int,int>& b){
            return a.second>b.second;
        });
        for(int i=0;i<k;i++)
            res[i]=freq[i].first;
        return res;
    }
};