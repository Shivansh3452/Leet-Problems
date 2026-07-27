class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n=nums.size();
        sort(begin(nums),end(nums));
        int fst=nums[n-1]*nums[n-2]*nums[n-3];
        int scnd=nums[0]*nums[1]*nums[n-1];
        return max(fst,scnd);
    }
};