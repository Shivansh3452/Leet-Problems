class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int maxm=INT_MIN;
        int i=0;
        int j=n-1;
        while(i<j){
            maxm=max(maxm,nums[i]+nums[j]);
            i++;
            j--;
        }
        return maxm;
    }
};