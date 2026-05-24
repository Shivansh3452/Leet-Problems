class Solution {
public:
    bool checker(vector<int>& nums){
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1])
                return false;
        }
        return true;
    }
    bool check(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            rotate(nums.rbegin(),nums.rbegin()+1,nums.rend());
            if(checker(nums))
                return true;
        }
        return false;
    }
};