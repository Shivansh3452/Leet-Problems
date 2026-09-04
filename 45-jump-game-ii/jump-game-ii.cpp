class Solution {
public:
    int t[100001];
    int helper(int i,int n,vector<int>& nums){
        if(i>=n-1)
            return 0;
        if(t[i]!=-1)
            return t[i];
        int ans=INT_MAX;
        for(int j=i+1;j<=min(i+nums[i],n-1);j++){
            int val=helper(j,n,nums);
            if(val!=INT_MAX)
                ans=min(ans,1+val);
        }
        return t[i]=ans;
    }
    int jump(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        int ans=helper(0,nums.size(),nums);
        return ans;
    }
};