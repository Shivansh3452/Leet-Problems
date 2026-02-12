class Solution {
public:
    int t[1001][1001];
    int lis(vector<vector<int>> &pairs,int prev,int curr){
        if(curr==pairs.size())
            return 0;
        if(t[prev+1][curr]!=-1)
            return t[prev+1][curr];
        int taken=0;
        if(prev==-1 ||pairs[curr][0]>pairs[prev][1]){
            taken=1+lis(pairs,curr,curr+1);
        }
        int not_taken=lis(pairs,prev,curr+1);
        return t[prev+1][curr]=max(taken,not_taken);
    }

    int findLongestChain(vector<vector<int>>& pairs) {
    int n=pairs.size();
    memset(t,-1,sizeof(t));
    sort(begin(pairs),end(pairs));
    return lis(pairs,-1,0);
    }
};