class Solution {
public:
    int memo[101];
    int helper(int i,int n,vector<int> &nums){
        if(i>=n)
            return 0;
        if(memo[i]!=-1)
            return memo[i];
        int steal=nums[i]+helper(i+2,n,nums);
        int skip=helper(i+1,n,nums);

        return memo[i]=max(steal,skip);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        memset(memo,-1,sizeof(memo));
        return helper(0,n,nums);
    }
};