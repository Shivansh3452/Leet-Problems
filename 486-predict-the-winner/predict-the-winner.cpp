class Solution {
public:
    int helper(int i,int n,vector<int>& nums){
        if(i==n)
            return nums[i];
            int frstone=nums[i]-helper(i+1,n,nums);
            int lstone=nums[n]-helper(i,n-1,nums);
        return max(frstone,lstone);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        int ans=helper(0,n-1,nums);
        return ans>=0;
    }
};