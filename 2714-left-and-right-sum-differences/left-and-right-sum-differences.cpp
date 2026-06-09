class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int> lft(n);
        vector<int> rght(n);

        lft[0]=nums[0];
        rght[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            lft[i]=lft[i-1]+nums[i];
        }
        for(int i=n-2;i>=0;i--){
            rght[i]=rght[i+1]+nums[i];
        }
        for(int i=0;i<n;i++){
            nums[i]=abs(rght[i]-lft[i]);
        }
        return nums;
    }
};