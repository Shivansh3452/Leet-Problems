class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int minm=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                minm=min(minm,abs(i-start));
            }
        }
        return minm;
    }
};