class Solution {
public:
    int t[13][10001];   //phla hai coin and dusra hai sum
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        memset(t,-1,sizeof(t));
        for(int i=0;i<=n;i++){
            t[i][0]=0;
        }
        for(int j=1;j<=amount;j++){
            t[0][j]=INT_MAX-1;
        }
        int i=1;
        for(int j=1;j<=amount;j++){
            if(j%coins[0]==0)
                t[i][j]=j/coins[0];
            else
                t[i][j]=INT_MAX-1;
        }
        for(int i=2;i<=n;i++){
            for(int j=1;j<=amount;j++){
                if(coins[i-1]<=j)
                    t[i][j]=min(t[i][j-coins[i-1]]+1,t[i-1][j]);
                else
                    t[i][j]=t[i-1][j];
            }
        }
        return t[n][amount]>=INT_MAX-1?-1:t[n][amount];
    }
};