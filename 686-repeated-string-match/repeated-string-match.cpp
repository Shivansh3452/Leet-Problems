class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int count=1;
        string str=a;
        while(a.size()<b.size()){
            a+=str;
            count++;
        }
        if(a.find(b)!=string::npos){
            return count;
        }
        a+=str;
        count++;
        if(a.find(b)!=string::npos){
            return count;
        }
        return -1;
    }
};