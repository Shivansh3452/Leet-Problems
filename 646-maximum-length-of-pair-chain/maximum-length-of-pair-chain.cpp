class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),
        [&](vector<int> &a,vector<int> &b){
            return a[1]<b[1];
        });
        int count=1;
        int n=pairs.size();
        int lst_end=pairs[0][1];
        for(int i=1;i<n;i++){
            if(pairs[i][0]>lst_end){
                count++;
                lst_end=pairs[i][1];
            } 
        }
        return count;
    }
};