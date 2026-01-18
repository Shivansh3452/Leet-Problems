class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n=nums.size();
        unordered_map<int,int> mpp;
        vector<long long> prefsum(n);
        prefsum[0]=nums[0];
        for(int i=1;i<n;i++){
            prefsum[i]=prefsum[i-1]+nums[i];
        }
        int target=prefsum[n-1]%p;
        if(target==0)
            return 0;
        mpp[0]=-1;
        int minlen=n;
        for(int i=0;i<n;i++){
            int currmod=prefsum[i]%p;
            int needed=(currmod-target+p)%p;
            if(mpp.find(needed)!=mpp.end()){
                minlen=min(minlen,i-mpp[needed]);
            }
            mpp[currmod]=i;
        }
        if(minlen!=n)
            return minlen;
        return -1; 
    }
};