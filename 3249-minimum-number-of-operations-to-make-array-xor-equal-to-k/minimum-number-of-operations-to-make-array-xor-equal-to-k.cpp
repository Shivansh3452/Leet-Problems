class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int total=0;
        for(auto& num:nums){
            total^=num;
        }
        int diffbit=(total^k);
        return __builtin_popcount(diffbit);
    }
};