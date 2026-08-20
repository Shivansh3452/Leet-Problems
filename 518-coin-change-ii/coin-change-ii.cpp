int t[5001][5001];
class Solution {
public:
    int helper(int i,int amount,int n,vector<int>& nums){
        if(amount==0)
            return 1;
        if(amount<0||i==n)
            return 0;
        if(t[i][amount]!=-1)
            return t[i][amount];
        int ways=0;
        //take
        ways+=helper(i,amount-nums[i],n,nums);
        //leave
        ways+=helper(i+1,amount,n,nums);
        return t[i][amount]=ways;
    }
    int change(int amount, vector<int>& nums) {
        memset(t,-1,sizeof(t));
        return helper(0,amount,nums.size(),nums);
    }
};