class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        int maxEl=INT_MIN;
        for(int i=0;i<nums.size();i++){
            pq.push({nums[i][0],i,0});
            maxEl=max(maxEl,nums[i][0]);
        }

        vector<int> resrange={-1000000,1000000};

        while(!pq.empty()){
            vector<int> curr=pq.top();
            pq.pop();
            
            int minEl=curr[0];
            int listIdx=curr[1];
            int idx=curr[2];

            if(maxEl-minEl<resrange[1]-resrange[0]){
                resrange[1]=maxEl;
                resrange[0]=minEl;
            }
            if(idx+1<nums[listIdx].size()){     //decrease the range from min side
                int nextEl=nums[listIdx][idx+1];
                pq.push({nextEl,listIdx,idx+1});
                maxEl=max(maxEl,nextEl);
            }
            else{
                break;
            }
        }
        return resrange;
    }
};