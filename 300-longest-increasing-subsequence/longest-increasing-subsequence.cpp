class Solution {
public:
    int t[2501][2501];
    int helper(int i,int prev,int n,vector<int>& nums){
        if(i>=n)
            return 0;
        if(prev!=-1&&t[i][prev]!=-1)
            return t[i][prev];
        //take
        int take=0;
        int skip=0;
        if(prev==-1||nums[i]>nums[prev])
            take=1+helper(i+1,i,n,nums);
        skip=helper(i+1,prev,n,nums);
        return prev!=-1?t[i][prev]=max(take,skip):max(take,skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        return helper(0,-1,nums.size(),nums);
    }
};