class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n=tickets.size();
        queue<pair<int,int>> q;
        int count=0;
        for(int i=0;i<tickets.size();i++){
            q.push({tickets[i],i});
        }
        while(!q.empty()){
            int temp=q.front().first;
            int idx=q.front().second;
            q.pop();
            temp--;
            count++;
            if(temp>0){
                q.push({temp,idx});
            }
            if(temp==0&& idx==k){
                return count;
            }
        }
        return -1;
    }
};