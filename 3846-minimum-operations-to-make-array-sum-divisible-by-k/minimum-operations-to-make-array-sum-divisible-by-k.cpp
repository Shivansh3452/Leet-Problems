class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        // if(sum<k){
        //     return sum;
        // }
        int count=0;
        long long diff=sum%k;
        int j=0;
        while(j<nums.size()&& diff>0){
            while(nums[j]>0 && diff!=0){
                nums[j]--;
                count++;
                diff--;
            }
            j++;
        }
        return count;
    }
};