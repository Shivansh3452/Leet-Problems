class Solution {
public:
    int t[100][100];
    int helper(int i, int n, vector<int>& nums) {
        if (i == n)
            return nums[i];
        if (t[i][n] != -1)
            return t[i][n];
        int frstone = nums[i] - helper(i + 1, n, nums);
        int lstone = nums[n] - helper(i, n - 1, nums);
        t[i][n]= max(frstone, lstone);
        return t[i][n];
    }
    bool predictTheWinner(vector<int>& nums) {
        memset(t, -1, sizeof(t));
        int n = nums.size();
        int ans = helper(0, n - 1, nums);
        return ans >= 0;
    }
};