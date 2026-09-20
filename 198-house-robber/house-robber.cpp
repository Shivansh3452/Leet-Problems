class Solution {
public:
    int t[401];
    int helper(int i,int n,vector<int>& nums){
        if(i>=n)
            return 0;
        if(t[i]!=-1)
            return t[i];
        int take=nums[i]+helper(i+2,n,nums);
        int skip=helper(i+1,n,nums);
        return t[i]=max(take,skip);
    }
    int rob(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        return max(helper(0,nums.size(),nums),helper(1,nums.size(),nums));
    }
};