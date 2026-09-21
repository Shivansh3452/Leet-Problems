class Solution {
public:
    bool isHappy(int n) {
        if(n==1)
            return true;
        set<int> st;
        while(n!=1){
            if(st.find(n)!=st.end())
                return false;
            st.insert(n);
            int sum=0;
            while(n){
                int temp=pow(n%10,2);
                sum+=temp;
                n/=10;
            }
            n=sum;
        }
        return true;
    }
};