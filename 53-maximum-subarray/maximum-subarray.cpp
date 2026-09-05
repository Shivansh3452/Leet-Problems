class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxm=nums[0];
        int maxsofar=nums[0];
        for(int i=1;i<nums.size();i++){
            maxsofar=max(nums[i],nums[i]+maxsofar);
            maxm=max(maxm,maxsofar);
        }
        return maxm;
    }
};