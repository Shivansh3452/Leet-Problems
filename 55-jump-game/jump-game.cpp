class Solution {
public:
    int t[100001];
    bool helper(int i,int n,vector<int>& nums){
        if(i>=n-1)
            return t[i]=1;
        if(t[i]!=-1)
            return t[i];
        for(int j=1;j<=nums[i];j++){
            if(i+j<n&&helper(i+j,n,nums))
                return t[i]=1;
        }
        return t[i]=0;
    }
    bool canJump(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        int n=nums.size();
        return helper(0,n,nums);
    }
};