class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> mpp;
        int ans=0;
        mpp[0]=1;
        for(int i=0;i<n;i++){
            if(i>0){
                nums[i]+=nums[i-1];
            }
            int rem=nums[i]%k;
            if(rem<0)
                rem+=k;
            ans+=mpp[rem];
            mpp[rem]++;
        }
        return ans;
    }
};