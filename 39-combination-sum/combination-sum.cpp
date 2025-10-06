class Solution {
public:
    vector<vector<int>> ans;

    void solve(int i,vector<int>& candidates, int target,vector<int>& temp){
        if(i==candidates.size()){
            int sum=0;
            for(int j=0;j<temp.size();j++){
                sum+=temp[j];
            }
            if(sum==target){
                ans.push_back(temp);
            }
            return;
        }
        int sum=0;
        for(int i=0;i<temp.size();i++){
            sum+=temp[i];
        }
        if(sum>target){
            return;
        }
        if(sum==target){
            ans.push_back(temp);
            return;
        }

        temp.push_back(candidates[i]);
        solve(i,candidates,target,temp);
        temp.pop_back();
        solve(i+1,candidates,target,temp);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        solve(0,candidates,target,temp);
        return ans; 
    }
};