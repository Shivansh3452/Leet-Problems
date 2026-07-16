class Solution {
public:
    typedef long long ll;
    ll gcd(ll x,ll y){
        if(y==0)
            return x;
        return gcd(y,x%y);
    }
    long long gcdSum(vector<int>& nums) {
        int maxm=INT_MIN;
        vector<ll> ans;
        for(ll i=0;i<nums.size();i++){
            if(nums[i]>maxm){
                maxm=nums[i];
            }
            ans.push_back(gcd(nums[i],maxm));
        }
        sort(begin(ans),end(ans));
        ll n=ans.size();
        ll l=0,r=n-1;
        ll fin=0;
        while(l<r){
            fin+=gcd(ans[l],ans[r]);
            l++;
            r--;
        }
        return fin;
    }
};