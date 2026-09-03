class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> lft(n),rght(n);
        lft[0]=height[0];
        rght[n-1]=height[n-1];
        for(int i=1;i<n;i++){
            lft[i]=max(lft[i-1],height[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            rght[i]=max(rght[i+1],height[i+1]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int wtrlvl=min(lft[i],rght[i]);
            if(wtrlvl>=height[i])
                ans+=wtrlvl-height[i];
        }
        return ans;
    }
};