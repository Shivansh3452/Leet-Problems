class Solution {
public:
    int t[5001][2];
    int helper(int i,bool flag,int n,vector<int>& nums){
        if(i>=n)
            return 0;
        if(t[i][flag]!=-1)
            return t[i][flag];
        //eat 5 star and do nothing
        int faayda=helper(i+1,flag,n,nums);
        //bech do
        if(flag){
            faayda=max(faayda,nums[i]+helper(i+2,!flag,n,nums));
        }
        //kharid lo
        else
            faayda=max(faayda,-nums[i]+helper(i+1,!flag,n,nums));
        return t[i][flag]=faayda;

    }
    int maxProfit(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        return helper(0,false,nums.size(),nums);
    }
};