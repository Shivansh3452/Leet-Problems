class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size())
            return false;
        int n=s.size();
        int m=goal.size();
        for(int start=0;start<m;start++){
            if(goal[start]==s[0]){
                int j=start;
                bool match=true;
                for(int i=0;i<n;i++){
                    if(goal[j]!=s[i]){
                        match=false;
                        break;
                    }
                    j=(j+1)%m;
                }
                if(match)
                    return true;
            }
        }
        return false;
    }
};