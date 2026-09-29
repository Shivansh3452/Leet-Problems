class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        for(auto& it:nums)
            mpp[it]++;
        vector<pair<int,int>> v(begin(mpp),end(mpp));
        sort(v.begin(), v.end(), [&](pair<int,int>& a, pair<int,int>& b){
            return a.second>b.second;}
        );
        vector<int> ans;
            for(auto& it:v){
                if(k==0)
                    return ans;
                ans.push_back(it.first);
                k--;
        }
        return ans;
    }
};