class Solution {
public:

    typedef pair<int,int> P;
    int helper(unordered_map<int,int> mpp,int x){
        priority_queue<P,vector<P>,greater<P>> pq;
        for(auto& it:mpp){
            pq.push({it.second,it.first});
            if(pq.size()>x)
                pq.pop();
        }
        int sum=0;
        while(!pq.empty()){
            auto [freq,val]=pq.top();
            pq.pop();
            sum+=freq*val;
        }
        return sum;
    }

    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n=nums.size();
        unordered_map<int,int> mpp;
        vector<int> ans;
        int i=0;
        int j=0;
        while(j<n){
            mpp[nums[j]]++;
            if(j-i+1==k){
                ans.push_back(helper(mpp,x));
                mpp[nums[i]]--;
                if(mpp[nums[i]]==0){
                    mpp.erase(nums[i]);
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};