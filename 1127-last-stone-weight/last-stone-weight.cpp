class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(),stones.end());     //max heap
        while(pq.size()>1){
            int num1=pq.top();
            pq.pop();
            int num2=pq.top();
            pq.pop();
            int diff=num1-num2;
            if(diff!=0)
                pq.push(diff);
        }
        if(pq.empty())
            return 0;
        return pq.top();
    }
};