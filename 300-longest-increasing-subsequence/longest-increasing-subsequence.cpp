class Solution {
public:

    int t[2501][2501];
    int len=0;
    int helper(int i,int prev,vector<int>& nums){
        if(i>=nums.size())
            return 0;
        if(t[i][prev+1]!=-1)
            return t[i][prev+1];
        //skip wala maal
        int skip=helper(i+1,prev,nums);
        int take=0;
        if(prev==-1||nums[i]>nums[prev]){
            take=1+helper(i+1,i,nums);
        }
        return t[i][prev+1]=max(take,skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        return helper(0,-1,nums);
    }
};