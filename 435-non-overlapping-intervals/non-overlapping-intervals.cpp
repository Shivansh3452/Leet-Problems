class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& nums) {
        int count=0;
        sort(begin(nums),end(nums),[&](vector<int>& a,vector<int>& b){
            return a[1]<b[1];
        });
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            int kept=nums[i][1];
            if(kept>nums[i+1][0]){
                nums[i+1][1]=kept;
                count++;
            }
            kept=nums[i+1][1];
        }
        return count;
    }
};