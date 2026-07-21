class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n=s.size();
        int active=count(begin(s),end(s),'1');
        vector<int> nums;
        int i=0;
        while(i<n) {
            if(s[i]=='0') {
                int start=i;
                while(i<n&&s[i]=='0')
                    i++;
                nums.push_back(i-start);
            } 
            else
                i++;
        }
        int maxm=0;
        for(int i=1;i<nums.size();i++){
            maxm=max(maxm,nums[i-1]+nums[i]);
        }
        return maxm+active;
    }
};