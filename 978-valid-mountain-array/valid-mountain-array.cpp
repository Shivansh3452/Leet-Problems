class Solution {
public:
    bool validMountainArray(vector<int>& nums) {
        int n = nums.size();
        if(n<3)
            return false;
        int idx=-1;
        for(int i=1;i<n-1;i++){
            if(nums[i]>nums[i-1]&&nums[i]>nums[i+1]){
                idx=i;
                break;
            }
        }
        if(idx==-1)
            return false;
        for(int i=0;i<idx;i++){
            if(nums[i]>=nums[i+1])
                return false;
        }
        for(int i=idx;i<n-1;i++){
            if(nums[i]<=nums[i+1])
                return false;
        }
        return true;
    }
};