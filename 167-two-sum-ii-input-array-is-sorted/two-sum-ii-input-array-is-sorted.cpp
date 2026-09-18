class Solution {
public:
    vector<int> helper(int i,int j,vector<int>& nums,int target){
        if(i>=j)
            return {};
        int sum=nums[i]+nums[j];
        if(sum==target)
            return {i+1,j+1};
        if(sum<target)
            return helper(i+1,j,nums,target);
        return helper(i,j-1,nums,target);
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        return helper(0,nums.size()-1,nums,target);
    }
};