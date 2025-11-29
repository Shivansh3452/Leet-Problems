class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        vector<long long> prefix(n, 0);
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }

        const long long INF = LONG_MAX;

        vector<long long> minPref(k, INF);
        minPref[k - 1] = 0;

        long long ans = LLONG_MIN;

        for (int i = 0; i < n; i++) {
            int r = i % k;

            if (minPref[r] != INF) {
                ans = max(ans, prefix[i] - minPref[r]);
            }
            minPref[r] = min(minPref[r], prefix[i]);
        }

        return ans;
    }
};
