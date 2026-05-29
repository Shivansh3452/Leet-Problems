class Solution {
public:

    int helper(int n){
        if(n<=0)
            return 0;
        return n%10+helper(n/10);
    }
    int minElement(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            nums[i]=helper(nums[i]);
        }
        int minm=INT_MAX;
        for(auto& it:nums){
            minm=min(minm,it);
        }
        return minm;
    }
};