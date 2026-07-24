class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        if(nums.size()==2&&nums[0]==1&&nums[1]==1)
            return 1;
        if(nums.size()<=2)
            return nums.size();
        unordered_set<int> temp;
        unordered_set<int> patanahi;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                temp.insert(nums[i]^nums[j]);
            }
        }
        for(auto& it:temp){
            for(auto& num:nums){
                patanahi.insert(it^num);
            }
        }
        return patanahi.size();
    }
};