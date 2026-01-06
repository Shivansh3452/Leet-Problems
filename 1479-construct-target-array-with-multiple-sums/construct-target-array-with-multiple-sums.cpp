class Solution {
public:
    bool isPossible(vector<int>& target) {
        int n=target.size();
        vector<int> ans(n, 1);
        while(true){
            int maxm=INT_MIN;
            int idx=-1;
            long long sum=0;
            for (int i=0;i<n;i++){
                sum+=target[i];
                if(target[i]>maxm) {
                    maxm=target[i];
                    idx=i;
                }
            }
            if(maxm==1)
                return true;
            long long rest=sum-maxm;
            if(rest==1)
                return true;
            if(rest==0||maxm<=rest)
                return false;
            int prev = maxm % rest;
            if (prev == 0)
                return false;

            target[idx] = prev;
        }
    }
};
