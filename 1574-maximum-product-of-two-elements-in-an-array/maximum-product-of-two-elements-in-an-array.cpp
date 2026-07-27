class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxm,secmaxm;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=maxm){
                secmaxm=maxm;
                maxm=nums[i];
            }
            else if(nums[i]<maxm&&nums[i]>=secmaxm){
                secmaxm=nums[i];
            }
        }
        return (maxm-1)*(secmaxm-1);
    }
};