class Solution {
public:
    long long sumAndMultiply(int n) {
        if(n==0)
            return 0;
        string s=to_string(n);
        string ans="";
        for(char& c:s){
            if(c!='0'){
                ans+=c;
            }
        }
        long long x=stoi(ans);
        long long sum=0;
        long long temp=x;
        while(temp>0){
            sum+=temp%10;
            temp/=10;
        }
        return x*sum;
    }
};