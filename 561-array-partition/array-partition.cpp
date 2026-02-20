class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int total=0;
        for(int i=0;i<nums.size();i+=2){
            total+=nums[i];
        }
        return total;
    }
};