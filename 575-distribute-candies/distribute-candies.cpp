class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        set<int> s(begin(candyType),end(candyType));
        return std::min((int)s.size(),(int)candyType.size()/2);
    }
};