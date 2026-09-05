class Solution {
public:
    void helper(vector<int>& temp,vector<bool>& vis,vector<vector<int>>& ans,vector<int>& nums){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(vis[i])
                continue;
            temp.push_back(nums[i]);
            vis[i]=true;
            helper(temp,vis,ans,nums);
            temp.pop_back();
            vis[i]=false;
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;
        vector<bool> vis(nums.size());
        helper(temp,vis,ans,nums);
        return ans;
    }
};