class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int target=(n*(n+1))/2;
        int sum=accumulate(begin(nums),end(nums),0);
        return target-sum;
    }
};