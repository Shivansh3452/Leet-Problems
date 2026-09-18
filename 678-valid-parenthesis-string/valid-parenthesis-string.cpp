class Solution {
public:
    bool checkValidString(string s) {
       stack<int> open;
        stack<int> star;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')
                open.push(i);
            else if(s[i]=='*')
                star.push(i);
            else{       //c==')'
                if(!open.empty()){
                    open.pop();
                }
                else if(!star.empty()){   //open is less and it's time for *
                    star.pop();
                }
                else
                    return false;
            }
        }
        if(open.empty())
            return true;
        else{
            while(!open.empty()&&!star.empty()){
                if(open.top()>star.top())
                    return false;
                open.pop();
                star.pop();
            }
            if(open.empty())
                return true;
        }
        return false;
    }
};