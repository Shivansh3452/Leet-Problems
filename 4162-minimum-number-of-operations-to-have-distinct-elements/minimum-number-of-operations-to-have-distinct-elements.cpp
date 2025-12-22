class Solution{
public:
    int minOperations(vector<int>& nums){
        unordered_set<int>seen;
        int n=nums.size();
        int badIndex=n;
        for(int i=n-1;i>=0;i--){
            if (seen.count(nums[i])){
                badIndex=i;
                break;
            }
            seen.insert(nums[i]);
        }
        if(badIndex==n)
            return 0;
        return (badIndex+3)/3;
    }
};
