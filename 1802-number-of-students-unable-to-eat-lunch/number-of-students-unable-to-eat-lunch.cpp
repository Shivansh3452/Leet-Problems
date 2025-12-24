class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        int unable=0;
        for(auto&s:students){
            q.push(s);
        }
        int i=0;
        while(!q.empty()&&unable<q.size()){
            if(q.front()==sandwiches[i]){
                unable=0;
                q.pop();
                i++;
            }
            else{
                q.push(q.front());
                q.pop();
                unable++;
            }
        }
        return q.size();
    }
};
/*
circular=0;
square=1
student stand in q
# of sandoicchi==# of students
sandoicchi are placed in stack
if student at front want st.top sandoicchi then st.pop() and q.pop() 
else int temp=q.front()-> q.pop()-> p.push(temp)


We do NOT compare “next cycle” manually
Instead, we track how many students failed consecutively for the same sandwich
*/