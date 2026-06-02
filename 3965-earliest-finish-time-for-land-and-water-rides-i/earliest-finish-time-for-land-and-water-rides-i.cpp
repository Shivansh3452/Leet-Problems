class Solution {
public:
    int earliestFinishTime(vector<int>& land, vector<int>& landDuration, vector<int>& water, vector<int>& waterDuration) {
        int n=land.size();
        int m=water.size();
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int landFinish=land[i]+landDuration[i];
                int waterStart=max(landFinish,water[j]);
                int finish1=waterStart+waterDuration[j];
                int waterFinish=water[j]+waterDuration[j];
                int landStart=max(waterFinish,land[i]);
                int finish2=landStart+landDuration[i];
                ans=min(ans,min(finish1,finish2));
            }
        }
        return ans;
    }
};