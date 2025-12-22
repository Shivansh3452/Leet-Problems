class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int i=1;
        int t=0;
        while(i<=n && t<target.size()){
            if(i!=target[t]){
                ans.push_back("Push");
                ans.push_back("Pop");
            }
                
            else{
                ans.push_back("Push");
                t++;
            }
            i++;
        }
        return ans;
    }
};
