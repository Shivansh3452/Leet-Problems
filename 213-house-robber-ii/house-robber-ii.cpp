class Solution {
public:

    int t[101];
    int solver(int i,int n,vector<int> nums){
        if(i>n)
            return 0;
        if(t[i]!=-1)
            return t[i];
        int steal=nums[i]+solver(i+2,n,nums);
        int skip=solver(i+1,n,nums);
        return t[i]=max(steal,skip);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return nums[0];
        memset(t,-1,sizeof(t));
        int case1=solver(0,n-2,nums);
        memset(t,-1,sizeof(t));
        int case2=solver(1,n-1,nums);
        return max(case1,case2);
    }
};