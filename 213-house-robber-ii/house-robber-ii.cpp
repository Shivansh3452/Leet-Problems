class Solution {
public:
    int t[10000];
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return nums[0];
        if (n == 2) 
            return max(nums[0], nums[1]);

        //case 1 when we take first house and thus not take the last house
        t[0]=0;
        t[1]=nums[0];
        for(int i=2;i<=n-1;i++){
            int skip=t[i-1];
            int take=nums[i-1]+t[i-2];
            t[i]=max(skip,take);
        }
        int result1=t[n-1];


        // case 2 when we do not take the first house
        t[0]=0;
        t[1]=0;
        for(int i=2;i<=n;i++){
            int skip=t[i-1];
            int take=nums[i-1]+t[i-2];
            t[i]=max(skip,take);
        }
        int result2=t[n];

        return max(result1,result2);
    }
};