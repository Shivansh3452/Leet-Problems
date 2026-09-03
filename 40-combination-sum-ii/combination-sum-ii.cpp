class Solution {
public:
    int t[101][101];
    vector<vector<int>> ans;
    void helper(int i,vector<int> temp,vector<int>& nums,int target){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(i>=nums.size()||target<0||nums[i]>target)
            return;
        temp.push_back(nums[i]);
        helper(i+1,temp,nums,target-nums[i]);
        temp.pop_back();
        int j=i;
        while(j<nums.size()&&nums[j]==nums[i])
            j++;
        helper(j, temp, nums, target);
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        memset(t,-1,sizeof(t));
        sort(nums.begin(),nums.end());
        vector<int> temp;
        helper(0,temp,nums,target);
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};