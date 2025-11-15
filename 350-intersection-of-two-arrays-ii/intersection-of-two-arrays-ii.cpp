class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int,int> mpp;
        vector<int>& shorter=nums1.size()>nums2.size()?  nums2:nums1;
        for(auto& num:shorter){
            mpp[num]++;
        }
        vector<int>& larger=nums1.size()>nums2.size()? nums1:nums2;
        for(auto& num:larger){
            if(mpp.find(num)!=mpp.end()&& mpp[num]>0){
                ans.push_back(num);
                mpp[num]--;
            }
        }
        return ans;
    }
};