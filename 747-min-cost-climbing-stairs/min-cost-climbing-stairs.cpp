class Solution {
public:
    int t[1001];
    int helper(int i,int n,vector<int>& nums){
        if(i>=n)
            return 0;
        if(t[i]!=-1)
            return t[i];
        //take 1 step
        int one=nums[i]+helper(i+1,n,nums);
        //take 2 steps
        int two=nums[i]+helper(i+2,n,nums);
        return t[i]=min(one,two);
    }
    int minCostClimbingStairs(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        int n=nums.size();
        int ans=min(helper(0,n,nums),helper(1,n,nums));
        return ans;
    }
};