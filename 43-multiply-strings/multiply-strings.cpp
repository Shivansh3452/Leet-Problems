class Solution {
public:
    string multiply(string nums1, string nums2) {
        int l1=nums1.length();
        int l2=nums2.length();
        vector<int> ans(l1+l2,0);
        for(int i=l1-1;i>=0;i--){
            int dig1=nums1[i]-'0';
            for(int j=l2-1;j>=0;j--){
                int dig2=nums2[j]-'0';
                ans[i+j+1]+=dig1*dig2;
            }
        }
        for(int i=ans.size()-1;i>=1;i--){
            ans[i-1]+=ans[i]/10;
            ans[i]%=10;
        }
        int idx=0;
        while(idx<ans.size()&&ans[idx]==0)
            idx++;
        if(idx==ans.size())
            return "0";
        string res="";
        for(int i=idx;i<ans.size();i++){
            res+=to_string(ans[i]);
        }
        return res;
    }
};