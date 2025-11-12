class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();

        unordered_map<long,long> mpp;
        for(auto& num:nums1){
            mpp[num]+=m;
        }
        for(auto& num:nums2){
            mpp[num]+=n;
        }
        int res=0;
        for(auto& it:mpp){
            long num=it.first;
            long freq=it.second;
            if(freq%2!=0){
                res^=num;
            }
        }
        return res;
    }
};