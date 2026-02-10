class Solution {
public:
    int t[46];
    int solve(int n){
        if(n<0)     //no way for less than 0 stairs
            return 0;
        if(t[n]!=-1)
            return t[n];
        if(n==0)
            return 1;   //only one way for 0 stairs
        int onestep=solve(n-1);
        int twostep=solve(n-2);
        return t[n]=onestep+twostep;
    }
    int climbStairs(int n) {
        memset(t,-1,sizeof(t));
       return solve(n);
    }
};