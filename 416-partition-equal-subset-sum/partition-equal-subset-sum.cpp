class Solution {
public:
    int t[201][10001];
    bool helper(int i,int n,int sum,vector<int>& nums,int curr){
        if(curr==sum)
            return true;
        if(i>=n||curr>sum)
            return false;
        if(t[i][curr]!=-1)
            return t[i][curr];
        //take
        if(helper(i+1,n,sum,nums,curr+nums[i]))
            return t[i][curr]=true;
        //skip
        if(helper(i+1,n,sum,nums,curr))
            return t[i][curr]=true;
        return t[i][curr]=false;
    }
    bool canPartition(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        int sum=accumulate(begin(nums),end(nums),0);
        if(sum%2!=0)
            return false;
        sum/=2;
        return helper(0,nums.size(),sum,nums,0);
    }
};