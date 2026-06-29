class Solution {
public:
    bool helper(vector<int>& nums){
        for(int i=1;i<nums.size();i++){
            if(nums[i]==1)
                return true;
        }
        return false;
    }
    int maximumElementAfterDecrementingAndRearranging(vector<int>& nums) {
        sort(begin(nums),end(nums));
        if(nums[0]!=1){
            bool onepresent=helper(nums);
            if(!onepresent){
                nums[0]=1;
            }
            else{
                for(int i=1;i<nums.size();i++){
                    if(nums[i]==1){
                        swap(nums[0],nums[1]);
                    }
                }
            }
        }
        for(int i=1;i<nums.size();i++){
            if(abs(nums[i-1]-nums[i])>1){
                nums[i]=nums[i-1]+1;
            }
        }
        int maxm=INT_MIN;
        for(int i=0;i<nums.size();i++){
            maxm=max(maxm,nums[i]);
        }
        return maxm;
    }
};