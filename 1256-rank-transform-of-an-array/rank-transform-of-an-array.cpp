class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& nums) {
        int n=nums.size();
        vector<int> temp=nums;
        sort(begin(temp),end(temp));
        map<int,int> mpp;
        int rank=1;
        for(int i=0;i<n;i++){
            if(mpp.find(temp[i])==mpp.end()){
                mpp[temp[i]]=rank;
                rank++;
            };
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            ans.push_back(mpp[nums[i]]);
        }
        return ans;
    }
};