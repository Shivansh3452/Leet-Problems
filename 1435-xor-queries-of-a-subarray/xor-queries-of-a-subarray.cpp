class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n=arr.size();
        for(int i=1;i<n;i++){
            arr[i]^=arr[i-1];
        }
        vector<int> res;
        for(auto& query:queries){
            int l=query[0];
            int r=query[1];

            int xor_val=l==0?arr[r]:(arr[r]^arr[l-1]);
            res.push_back(xor_val);
        }
        return res;
    }
};