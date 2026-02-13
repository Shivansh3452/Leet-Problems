class Solution {
public:

    long long t[100001][2];
    long long helper(int i,int n,bool flag,vector<int>& nums){
        if(i==nums.size())
            return 0;
        if(t[i][flag]!=-1)
            return t[i][flag];
        long long skip=helper(i+1,n,flag,nums);
        long long take;
        if(flag){
            take=nums[i]+helper(i+1,n,!flag,nums);
        }
        else{
            take=-nums[i]+helper(i + 1,n,!flag,nums);
        }
        return t[i][flag]=max(take,skip);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        bool flag=true;
        memset(t,-1,sizeof(t));
        return helper(0,n,flag,nums);
    }
};