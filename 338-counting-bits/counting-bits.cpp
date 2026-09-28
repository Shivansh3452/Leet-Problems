class Solution {
public:
    int helper(int nums){
        int count=0;
        while(nums){
            int num=nums&1;
            if(num==1)
                count++;
            nums>>=1;
        }
        return count;
    }
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0;i<=n;i++){
            ans.push_back(helper(i));
        }
        return ans;
    }
};