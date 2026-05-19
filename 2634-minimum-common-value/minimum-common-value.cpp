class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        set<int>st;
        st.insert(begin(nums1),end(nums1));
        for(auto& it:nums2){
            if(st.find(it)!=st.end())
                return it;
        }
        return -1;
    }
};