class Solution {
public:
    int helper(int sumOdd,int sumEven){
        return sumEven==0?sumOdd:gcd(sumEven,sumOdd%sumEven);
    }
    int gcdOfOddEvenSums(int n) {
        int sumOdd=n*n;
        int sumEven=n*(n+1);
        return helper(sumOdd,sumEven);
    }
};