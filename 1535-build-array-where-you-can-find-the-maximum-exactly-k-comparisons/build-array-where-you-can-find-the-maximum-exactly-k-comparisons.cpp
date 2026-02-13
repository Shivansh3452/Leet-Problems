class Solution {
public:
    int mod=1e9+7;
    int M, N, K;
    int t[101][101][101];
    int helper(int idx, int searchcost, int maxmsofar) {
        if(searchcost>K)
            return 0;
        if (idx == N) {
            if (searchcost == K) {
                return 1;
            }
            else
                return 0;
        }
        if(t[idx][searchcost][maxmsofar]!=-1)
            return t[idx][searchcost][maxmsofar];
        long long result = 0;
        for (int i = 1; i <= M; i++) {
            if (i > maxmsofar) {
                result=(result+helper(idx+1,searchcost+1,i))%mod;
            } 
            else
                result=(result+helper(idx+1,searchcost,maxmsofar))%mod;
        }
        return t[idx][searchcost][maxmsofar]=result%mod;
    }
int numOfArrays(int n, int m, int k) {
    M = m;
    N = n;
    K = k;
    memset(t,-1,sizeof(t));
    return helper(0, 0, 0);
}
};