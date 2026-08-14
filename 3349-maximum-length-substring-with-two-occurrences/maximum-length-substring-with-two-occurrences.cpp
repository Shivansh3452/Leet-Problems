class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int> nums(26,0);
        int lft=0;
        int maxLen=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            int ch=s[i]-'a';
            nums[ch]++;
            while(nums[ch]>2){
                int ch2=s[lft]-'a';
                nums[ch2]--;
                lft++;
            }
            int len=i-lft+1;
            if(len>maxLen){
                maxLen=len;
            }
        }
        return maxLen;
    }
};