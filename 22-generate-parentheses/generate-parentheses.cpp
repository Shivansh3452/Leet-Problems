class Solution {
public:
    vector<string>ans;
    bool isValid(string curr){
       int count=0;
       for(auto& it:curr){
        if(it=='(')
            count++;
        else if(it==')')
            count--;
        if(count<0)
            return false;
        }
        return count==0;
    }
    void solve(string curr,int n){
        if(curr.size()==2*n){
            if(isValid(curr)){
                ans.push_back(curr);
            }
            return;
        }
        curr.push_back('(');
        solve(curr,n);
        curr.pop_back();
        curr.push_back(')');
        solve(curr,n);
        curr.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        string curr="";
        solve(curr,n);
        return ans;
    }
};