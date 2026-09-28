class Solution {
public:
    int t[100001];
    int helper(int nums){
        int temp=nums;
        int count=0;
        if(t[temp]!=-1)
            return t[nums];
        while(nums){
            int num=nums&1;
            if(num==1)
                count++;
            nums>>=1;
        }
        return t[temp]=count;
    }
    vector<int> countBits(int n) {
        memset(t,-1,sizeof(t));
        vector<int> ans;
        for(int i=0;i<=n;i++){
            ans.push_back(helper(i));
        }
        return ans;
    }
};