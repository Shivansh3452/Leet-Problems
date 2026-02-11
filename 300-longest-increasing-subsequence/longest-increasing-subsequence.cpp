class Solution {
public:
    int t[2501][2501];
    int helper(int n,vector<int> &nums,int i,int prev){
        if(i>=n)
            return 0;
        if(prev!=-1 && t[i][prev]!=-1)
            return t[i][prev];
        int take=0;
        if(prev==-1||nums[i]>nums[prev]){
            take=1+helper(n,nums,i+1,i);
        }
        int skip=helper(n,nums,i+1,prev);

        if(prev!=-1)
            t[i][prev]=max(take,skip);
        return max(take,skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        memset(t,-1,sizeof(t));
        return helper(n,nums,0,-1);
    }
};