class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mpp;
        for(int i=0;i<n-1;i++){
            int sum=nums[i]+nums[i+1];
            mpp[sum]++;
        }
        for(auto& it:mpp){
            if(it.second>1){
                return true;
            }
        }
        return false;
    }
};