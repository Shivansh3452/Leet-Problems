class Solution {
public:
    vector<vector<int>>ans;
    void solve(int i,vector<int>& temp,vector<int>& nums,int target){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(target<0||i>=nums.size()) 
            return;
        temp.push_back(nums[i]);
        solve(i,temp,nums,target-nums[i]);
        temp.pop_back();
        solve(i+1,temp,nums,target);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> temp;
        solve(0,temp,nums,target);
        return ans;
    }
};