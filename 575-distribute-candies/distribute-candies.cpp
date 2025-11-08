class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n=candyType.size();
        unordered_map<int,int> mpp;
        for(auto& type: candyType){
            mpp[type]++;
        }
        return min((int)mpp.size(),n/2);
    }
};