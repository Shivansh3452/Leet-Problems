class Solution {
public:
    int clumsy(int n) {
        if(n<2)
            return n;
        
        stack<int> st;
        st.push(n);
        
        int flag=0;
        
        for(int i=n-1; i>=1; i--){
            if(flag==0){
                int temp=st.top();
                st.pop();
                st.push(temp*i);
                flag++;
            }
            else if(flag==1){
                int temp=st.top();
                st.pop();
                st.push(temp/i);
                flag++;
            }
            else if(flag==2){
                st.push(i);
                flag++;
            }
            else if(flag==3){
                st.push(-i);
                flag=0;
            }
        }
        
        int temp=0;
        while(!st.empty()){
            temp+=st.top();
            st.pop();
        }
        return temp;
    }
};