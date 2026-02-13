class Solution {
public:
    int t[401];
    int solver(int i,int n,vector<int>& nums){
        if(i>=n)
            return 0;
        if(t[i]!=-1)
            return t[i];
        //jab take krta h
        int steal=nums[i]+solver(i+2,n,nums);
        int skip=solver(i+1,n,nums);
        return t[i]=max(steal,skip);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        memset(t,-1,sizeof(t));
        return solver(0,n,nums);
    }
};