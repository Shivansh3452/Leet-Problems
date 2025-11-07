class Solution {
public:
    string countAndSay(int n) {
        if(n==1)
            return "1";
        int temp=1;
        string str="1";
        while(n>1){
            string res="";
            int count=1;
            for(int i=0;i<str.size();i++){
                if(i+1<str.size() && str[i]==str[i+1]){
                    count++;
                }
                else{
                    res+=to_string(count);
                    res+=str[i];
                    count=1;
                }  
            }
            str=res;
            n--;
        }
        return str;
    }
};