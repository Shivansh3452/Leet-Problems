class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        set<int> ans;
        queue<int> q;
        for(int i=0;i<=8;i++){
            q.push(i);
        }
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            if(temp>=low&&temp<=high)
                ans.insert(temp);
            int lst=temp%10;
            if(lst+1<=9)
                q.push(temp*10+(lst+1));
        }
        vector<int> st;
        for(auto& it:ans){
            st.push_back(it);
        }
        return st;
    }
};