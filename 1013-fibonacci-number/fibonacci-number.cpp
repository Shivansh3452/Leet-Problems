class Solution {
public:

    int solver(int n,vector<int> &dp){
        if(n<=1)
            return n;
        if(dp[n]!=-1)
            return dp[n];
        return dp[n]=solver(n-1,dp)+solver(n-2,dp);
    }
    int fib(int n) {
        if(n<=1)
            return n;
        vector<int> dp(n+1,-1);
        return solver(n,dp);
    }
};