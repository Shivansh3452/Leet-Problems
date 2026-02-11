class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {

        // 0 → even state (+)
        // 1 → odd state (-)
        int n=nums.size();
        vector<vector<long>>t(n+1,vector<long>(2,0));     //even ke liye 0 and odd ke liye 1
        for(int i=1;i<=n;i++){
            //even ke liye
            t[i][0]=max(t[i-1][0],t[i-1][1]+nums[i-1]);
            //odd ke liye
             t[i][1]=max(t[i-1][1],t[i-1][0]-nums[i-1]);
        }
        return t[n][0];
    }
};