class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n=colors.size();
        int took_time=0;
        for(int i=1;i<n;i++){
            if(colors[i]==colors[i-1]){
                took_time+=min(neededTime[i-1],neededTime[i]);
                neededTime[i]=max(neededTime[i-1],neededTime[i]);
            }
        }
        return took_time;
    }
};