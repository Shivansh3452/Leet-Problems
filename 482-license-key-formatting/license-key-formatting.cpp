class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string ans="";
        string temp="";
        for (auto& c:s){
            if(c=='-')
                continue;
            temp+=toupper(c);
        }
        int n=temp.size();
        if(n==0)
            return ans;
        int i=0;
        int first=n%k;
        if(first!=0){
            for(;i<first;i++){
                ans+=temp[i];
            }
            if(i<n)
                ans+='-';
        }
        int cnt=0;
        for(;i<n;i++){
            ans+=temp[i];
            cnt++;
            if(cnt==k && i!=n-1){
                ans+='-';
                cnt=0;
            }
        }
        return ans;
    }
};