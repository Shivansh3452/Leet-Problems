class Solution {
public:
    typedef long long ll;
    ll t[100001][2];

    ll helper(int i,int n,vector<int> &nums,bool flag){
        if(i>=n)
            return 0;
        if(t[i][flag]!=-1)
            return t[i][flag];
        ll skip=helper(i+1,n,nums,flag);     //skip wali condition
        ll val=nums[i];

        if(flag==false)    
            val=-val;
        ll take=val+helper(i+1,n,nums,!flag);  //take wali condition sign opposite

        return t[i][flag]=max(take,skip);
    }

    long long maxAlternatingSum(vector<int>& nums) {
        bool flag=true;   // to tell if the val indexed  is needed to subtract or add
        int n=nums.size();
        memset(t,-1,sizeof(t));
        return helper(0,n,nums,flag);
    }
};