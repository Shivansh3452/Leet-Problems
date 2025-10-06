class Solution {
public:
    vector<vector<int>> ans;

    void solve(int i,vector<int>& candidates, int target,vector<int>& temp){
        if(i==candidates.size()){
        int sum=0;
        for(int j= 0;j<temp.size();j++){
            sum+=temp[j];
        }
        if(sum==target){
            ans.push_back(temp);
        }
        return;
    }
    int sum=0;
    for(int j=0;j<temp.size();j++){
        sum+=temp[j];
    }
    if(sum>target){
        return;
    }
        temp.push_back(candidates[i]);
        solve(i+1,candidates,target,temp);
        temp.pop_back();
        while(i+1<candidates.size()&& candidates[i]==candidates[i+1]){
            i++;
        }
        solve(i+1,candidates,target,temp);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> temp;
        solve(0,candidates,target,temp);
        return ans; 
    }
};