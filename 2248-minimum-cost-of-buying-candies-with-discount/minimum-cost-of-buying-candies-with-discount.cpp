class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        sort(rbegin(nums),rend(nums));
        for(int i=0;i<n;i++){
            if((i+1)%3==0)
                continue;
            else
                ans+=nums[i];
        }
        return ans;
    }
};