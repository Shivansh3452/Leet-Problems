class Solution {
public:
    int reverseBits(int n) {
        int ans=0;
        int count=32;
        while(count--){
            int a=n&1;
            n>>=1;
            ans<<=1;
            ans=ans|a;
        }
        return ans;
    }
};