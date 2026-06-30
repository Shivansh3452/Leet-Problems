class Solution {
public:

    bool helper(vector<int>& temp){
        for(auto& it:temp){
            if(it==0)
                return false;
        }
        return true;
    }
    int numberOfSubstrings(string s) {
        int n=s.size(),ans=0,l=0;
        vector<int> temp(3,0);
        for(int i=0;i<s.size();i++){
            temp[s[i]-'a']++;
            while(helper(temp)){
                ans+=(n-i);
                temp[s[l]-'a']--;
                l++;
            }
        }
        return ans;
    }
};