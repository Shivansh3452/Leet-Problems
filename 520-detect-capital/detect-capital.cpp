class Solution {
public:
    bool detectCapitalUse(string word) {
        int n=word.size();
        char first=word[0];
        char second=word[1];
        if(first>='A'&&first<='Z'){
            if(second>='A'&&second<='Z'){       //sab maal bda ho
                for(int i=2;i<n;i++){
                    if(word[i]<'A'||word[i]>'Z')
                        return false;
                }
            }
    //jab second wala maal chota ho but first bda ho to sab chhote hone chahiye
            else{
                for(int i=1;i<n;i++){
                    if(word[i]>='A'&&word[i]<='Z')
                        return false;
                }
            }
        }
        else{
            //jab pehla maal hi chhota ho
            for(int i=1;i<n;i++){
                if(word[i]>='A'&&word[i]<='Z')
                    return false;
            }
        }
        return true; 
    }
};