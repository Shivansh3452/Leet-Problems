class Solution {
public:
    bool helper(int i,vector<int>& arr){
        for(int j=0;j<arr.size();j++){
            if(arr[j]==i)
                return true;
        }
        return false;
    }
    bool mergeTriplets(vector<vector<int>>& nums, vector<int>& target) {
        int n=nums.size();
        for(auto& it: nums){
            if(it[0]>target[0]||it[1]>target[1]||it[2]>target[2]){
                it[0]=INT_MIN;
                it[1]=INT_MIN;
                it[2]=INT_MIN;
            }
        }
        vector<int> fst(n),scnd(n),lst(n);
        for(int i=0;i<n;i++){
            fst[i]=nums[i][0];
            scnd[i]=nums[i][1];
            lst[i]=nums[i][2];
        }
        return helper(target[0],fst)&&helper(target[1],scnd)&&helper(target[2],lst);
    }
};