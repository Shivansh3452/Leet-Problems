class Solution {
public:
    int helper(int hr,int target,vector<int>& nums){
        long long currhr=0;
        for(int i=0;i<nums.size();i++){
            currhr+=((nums[i]+hr-1)/hr);
        }
        return currhr<=target;
    }
    int minEatingSpeed(vector<int>& nums, int h) {
        int i=1;
        int j=*max_element(nums.begin(),nums.end()),ans=0;
        while(i<=j){
            int mid=(i+j)/2;
            if(helper(mid,h,nums)){
                ans=mid;
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        return ans;
    }
};