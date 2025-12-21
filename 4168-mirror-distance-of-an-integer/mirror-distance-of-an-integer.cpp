class Solution {
public:
    int mirrorDistance(int n) {
        string rev_n=to_string(n);
        reverse(begin(rev_n),end(rev_n));
        int s=stoi(rev_n);
        return abs(s-n);
    }
};