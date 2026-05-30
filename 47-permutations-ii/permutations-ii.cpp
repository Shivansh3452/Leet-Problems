class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>>st;
        sort(begin(nums),end(nums));
        st.insert(nums);
        do{
            st.insert(nums);
        }while(next_permutation(nums.begin(),nums.end()));
        vector<vector<int>> ans(st.begin(),st.end());
        return ans;
    }
};