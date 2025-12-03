class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mpp;
        vector<int> ans;
        for(auto& num:nums){
            mpp[num]++;
        }
        for(int i=1;i<=n;i++){
            if(mpp[i]==0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};