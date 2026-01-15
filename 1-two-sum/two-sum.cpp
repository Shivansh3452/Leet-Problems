class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            int a=nums[i];
            int need=target-a;
            if(mpp.find(need)!=mpp.end()){
                return {mpp[need],i};
            }
        mpp[a]=i;
        }
        return {};
    }
};