class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int,vector<int>,less<int>> pq;
        for(auto &stone:stones){
            pq.push(stone);
        }
        while(pq.size()>1){
            int x=pq.top();
            pq.pop();
            int y=pq.top();
            pq.pop();

            if(x!=y){
                int temp=abs(x-y);
                pq.push(temp);
            }
            if(pq.empty()){
                return 0;
            }
        }
        return pq.top();
    }
};