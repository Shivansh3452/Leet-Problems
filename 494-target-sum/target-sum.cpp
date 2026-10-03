class Solution {
public:
    int helper(int i,int n,int curr,int target,vector<int>& nums){
        if(i==n){
            if(curr==target)
                return 1;
            return 0;
        }
        //plus kro
        int plus=helper(i+1,n,curr+nums[i],target,nums);
        //minus kro
        int minus=helper(i+1,n,curr-nums[i],target,nums);
        return plus+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int curr=0;
        return helper(0,nums.size(),curr,target,nums);
    }
};