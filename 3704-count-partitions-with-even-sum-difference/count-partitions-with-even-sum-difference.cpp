class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int count=0;
        int part=0;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        while(part!=nums.size()-1){
            int leftSum=0;
            for(int i=0;i<part;i++){
                leftSum+=nums[i];
            }
            int rightSum=sum-leftSum;
            if((rightSum-leftSum)%2==0){
                count++;
            }
            part++;
        }
        return count;
    }
};