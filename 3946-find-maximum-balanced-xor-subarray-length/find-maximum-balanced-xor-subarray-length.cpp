class Solution {
public:
    int maxBalancedSubarray(vector<int>& nums) {
        unordered_map<string,int> mpp;
        int n=nums.size();
        int prefixXor=0;
        int diff=0;
        int res=0;
        mpp["0#0"]=-1;
        for(int i=0;i<n;i++){
            prefixXor^=nums[i];
            if(nums[i]%2)       //odd
                diff++;
            else
                diff--;         //evem
            string key=to_string(prefixXor)+"#"+to_string(diff);
            if(mpp.contains(key))
                res=max(res,i-mpp[key]);
            else
                mpp[key]=i;
        }
        return res;
    }
};